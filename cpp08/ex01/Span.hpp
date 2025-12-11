#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <exception>
#include <limits>

class Span {
private:
    unsigned int maxSize;
    std::vector<int> numbers;

public:
    Span();
    Span(unsigned int N);
    Span(const Span& src);
    Span& operator=(const Span& src);
    ~Span();

    void addNumber(int number);
    unsigned int shortestSpan() const;
    unsigned int longestSpan() const;

    template <typename Iterator>
    void addRange(Iterator begin, Iterator end);

    class SpanFullException : public std::exception {
    public:
        const char* what() const throw() {
            return "Span is full - cannot add more numbers";
        }
    };

    class NoSpanException : public std::exception {
    public:
        const char* what() const throw() {
            return "Not enough numbers to calculate span (need at least 2)";
        }
    };
};

template <typename Iterator>
void Span::addRange(Iterator begin, Iterator end) {
    while (begin != end) {
        addNumber(*begin);
        ++begin;
    }
}

#endif