#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& src) { (void)src; }
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& src) { (void)src; return *this; }
ScalarConverter::~ScalarConverter() {}

enum Type {
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    INVALID
};

static Type detectType(const std::string& literal) {
    if (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'')
        return CHAR;
    
    if (literal == "nan" || literal == "nanf" ||
        literal == "inf" || literal == "inff" ||
        literal == "+inf" || literal == "+inff" ||
        literal == "-inf" || literal == "-inff")
        return (literal[literal.length() - 1] == 'f') ? FLOAT : DOUBLE;
    
    if (literal[literal.length() - 1] == 'f')
        return FLOAT;
    
    if (literal.find('.') != std::string::npos)
        return DOUBLE;

    return INT;
}

static void printChar(double value) {
    if (std::isnan(value) || std::isinf(value)) {
        std::cout << "char: impossible" << std::endl;
    } else if (value < 0 || value > 127) {
        std::cout << "char: impossible" << std::endl;
    } else if (value < 32 || value == 127) {
        std::cout << "char: Non displayable" << std::endl;
    } else {
        std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
    }
}

static void printInt(double value) {
    if (std::isnan(value) || std::isinf(value)) {
        std::cout << "int: impossible" << std::endl;
    } else if (value < std::numeric_limits<int>::min() || 
               value > std::numeric_limits<int>::max()) {
        std::cout << "int: impossible" << std::endl;
    } else {
        std::cout << "int: " << static_cast<int>(value) << std::endl;
    }
}

static void printFloat(double value) {
    float f = static_cast<float>(value);
    std::cout << "float: " << f;
    if (f == static_cast<int>(f) && !std::isnan(f) && !std::isinf(f))
        std::cout << ".0";
    std::cout << "f" << std::endl;
}

static void printDouble(double value) {
    std::cout << "double: " << value;
    if (value == static_cast<int>(value) && !std::isnan(value) && !std::isinf(value))
        std::cout << ".0";
    std::cout << std::endl;
}

void ScalarConverter::convert(const std::string& literal) {
    Type type = detectType(literal);
    double value = 0;
    
    try {
        switch (type) {
            case CHAR:
                value = static_cast<double>(literal[1]);
                break;
            case INT:
                value = static_cast<double>(std::atoi(literal.c_str()));
                break;
            case FLOAT:
                value = static_cast<double>(std::atof(literal.c_str()));
                break;
            case DOUBLE:
                value = std::atof(literal.c_str());
                break;
            case INVALID:
                std::cout << "Error: Invalid literal" << std::endl;
                return;
        }
    } catch (...) {
        std::cout << "Error: Conversion failed" << std::endl;
        return;
    }
    
    printChar(value);
    printInt(value);
    printFloat(value);
    printDouble(value);
}