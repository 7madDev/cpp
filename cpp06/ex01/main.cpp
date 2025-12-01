#include "Serializer.hpp"
#include <iostream>

int main() {
    Data* original = new Data();
    original->id = 42;
    original->name = "Test";
    original->value = 3.14f;
    
    std::cout << "=== Original Data ===" << std::endl;
    std::cout << "Address: " << original << std::endl;
    std::cout << "ID: " << original->id << std::endl;
    std::cout << "Name: " << original->name << std::endl;
    std::cout << "Value: " << original->value << std::endl;
    
    std::cout << "\n=== Serialization ===" << std::endl;
    uintptr_t raw = Serializer::serialize(original);
    std::cout << "Serialized (as integer): " << raw << std::endl;
    
    std::cout << "\n=== Deserialization ===" << std::endl;
    Data* result = Serializer::deserialize(raw);
    std::cout << "Address: " << result << std::endl;
    std::cout << "ID: " << result->id << std::endl;
    std::cout << "Name: " << result->name << std::endl;
    std::cout << "Value: " << result->value << std::endl;
    
    std::cout << "\n=== Verification ===" << std::endl;
    if (result == original) {
        std::cout << "✅ Success! Pointers match!" << std::endl;
    } else {
        std::cout << "❌ Error! Pointers don't match!" << std::endl;
    }
    
    if (result->id == original->id && 
        result->name == original->name && 
        result->value == original->value) {
        std::cout << "✅ Data is intact!" << std::endl;
    }
    
    delete original;
    
    return 0;
}