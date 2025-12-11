#include "Span.hpp"

Span::Span() : maxSize(0) {}

Span::Span(unsigned int N) : maxSize(N) {
    numbers.reserve(N);
}

Span::Span(const Span& src) : maxSize(src.maxSize), numbers(src.numbers) {}

Span& Span::operator=(const Span& src) {
    if (this != &src) {
        maxSize = src.maxSize;
        numbers = src.numbers;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int number) {
    if (numbers.size() >= maxSize) {
        throw SpanFullException();
    }
    numbers.push_back(number);
}

unsigned int Span::shortestSpan() const {
    if (numbers.size() < 2) {
        throw NoSpanException();
    }

    std::vector<int> sorted = numbers;
    std::sort(sorted.begin(), sorted.end());

    unsigned int minSpan = std::numeric_limits<unsigned int>::max();
    
    for (size_t i = 0; i < sorted.size() - 1; i++) {
        unsigned int span = sorted[i + 1] - sorted[i];
        if (span < minSpan) {
            minSpan = span;
        }
    }

    return minSpan;
}

unsigned int Span::longestSpan() const {
    if (numbers.size() < 2) {
        throw NoSpanException();
    }

    int minElement = *std::min_element(numbers.begin(), numbers.end());
    int maxElement = *std::max_element(numbers.begin(), numbers.end());

    return maxElement - minElement;
}