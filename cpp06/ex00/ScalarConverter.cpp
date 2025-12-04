#include "ScalarConverter.hpp"
#include <cctype>

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

static bool isValidInt(const std::string& str) {
    if (str.empty())
        return false;
    
    size_t i = 0;
    
    if (str[0] == '+' || str[0] == '-')
        i = 1;
    
    while (i < str.length()) {
        if (!std::isdigit(str[i]))
            return false;
        i++;
    }
    
    return true;
}

static bool isValidDouble(const std::string& str) {
    size_t i = 0;
    bool hasDigit = false;
    bool hasDot = false;
    
    if (str[0] == '+' || str[0] == '-')
        i = 1;
    
    if (str[str.length() - 1] == '.')
        return false;
    
    while (i < str.length()) {
        if (std::isdigit(str[i])) {
            hasDigit = true;
        } else if (str[i] == '.') {
            if (hasDot)
                return false;
            hasDot = true;
        } else {
            return false;
        }
        i++;
    }
    
    return hasDigit && hasDot;
}

static bool isValidFloat(const std::string& str) {
    if (str.length() < 2 || str[str.length() - 1] != 'f')
        return false;
    
    std::string withoutF = str.substr(0, str.length() - 1);
    return isValidDouble(withoutF);
}

static Type detectType(const std::string& literal) {
    if (literal.empty())
        return INVALID;

    if (literal.length() == 1 && !std::isdigit(literal[0]))
        return CHAR;

    if (literal == "nan" || literal == "nanf" ||
        literal == "inf" || literal == "inff" ||
        literal == "+inf" || literal == "+inff" ||
        literal == "-inf" || literal == "-inff")
        return (literal[literal.length() - 1] == 'f') ? FLOAT : DOUBLE;

    if (literal.length() > 0 && literal[literal.length() - 1] == 'f') {
        if (isValidFloat(literal))
            return FLOAT;
        return INVALID;
    }

    if (literal.find('.') != std::string::npos) {
        if (isValidDouble(literal))
            return DOUBLE;
    
        return INVALID;
    }

    if (isValidInt(literal))
        return INT;

    return INVALID;
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
                value = static_cast<double>(literal[0]);
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