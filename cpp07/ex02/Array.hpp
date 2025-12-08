#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>
#include <iostream>

template <typename T>
class Array
{
private:
    T* elements;
    size_t size;
public:
    Array();
    Array(size_t n);
    Array(const Array& src);
    Array& operator=(const Array& src);
    ~Array();

    T& operator[](size_t i);
    const T& operator[](size_t i) const;

    size_t getSize() const;

    class OutOfBoundsException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Index out of bounds";
        }
    };
};

template <typename T>
Array<T>::Array() : elements(NULL), size(0) {
    // std::cout << "Array default constructor called" << std::endl;
}

template <typename T>
Array<T>::Array(size_t n) : elements(NULL), size(n) {
    if (n > 0) {
        elements = new T[n];
    }
    // std::cout << "Array parametrized constructor called (size: " << n << ")" << std::endl;
}

template <typename T>
Array<T>::Array(const Array& src) : elements(NULL), size(src.size) {
    if (size > 0) {
        elements = new T[size];
        for (size_t i = 0; i < size; i++) {
            elements[i] = src.elements[i];
        }
    }
    // std::cout << "Array copy constructor called" << std::endl;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& src) {
    if (this != &src) {
        if (elements != NULL) {
            delete[] elements;
        }
        
        size = src.size;
        
        if (size > 0) {
            elements = new T[size];
            for (size_t i = 0; i < size; i++) {
                elements[i] = src.elements[i];
            }
        } else {
            elements = NULL;
        }
    }
    // std::cout << "Array assignment operator called" << std::endl;
    return *this;
}

template <typename T>
Array<T>::~Array() {
    if (elements != NULL) {
        delete[] elements; 
    }
    // std::cout << "Array destructor called" << std::endl;
}

template <typename T>
T& Array<T>::operator[](size_t i) {
    if (i >= size)
        throw OutOfBoundsException();

    return elements[i];
}

template <typename T>
const T& Array<T>::operator[](size_t i) const {
    if (i >= size)
        throw OutOfBoundsException();

    return elements[i];
}

template <typename T>
size_t Array<T>::getSize() const {
    return size;
}

#endif