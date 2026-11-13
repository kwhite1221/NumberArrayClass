#include "NumberArray.h"
#include <iostream>
#include <iomanip>

// Helper to validate whether an index falls within allocated bounds
bool NumberArray::isValidIndex(int index) const {
    return (index >= 0 && index < size);
}

// Constructor: Allocates dynamic array and initializes elements to 0.0
NumberArray::NumberArray(int sizeParam) {
    if (sizeParam <= 0) {
        std::cerr << "[Warning] Invalid size " << sizeParam
            << " specified. Defaulting to " << DEFAULT_SIZE << ".\n";
        size = DEFAULT_SIZE;
    }
    else {
        size = sizeParam;
    }

    data = new double[size];
    for (int i = 0; i < size; ++i) {
        data[i] = 0.0;
    }
}

// Destructor: Deallocates internal dynamic memory and confirms cleanup
NumberArray::~NumberArray() {
    delete[] data;
    data = nullptr;
    std::cout << "[Destructor] NumberArray with " << size
        << " elements successfully destroyed and memory deallocated.\n";
}

// Mutator: Safe, bounds-checked assignment
void NumberArray::setNumber(int index, double value) {
    if (isValidIndex(index)) {
        data[index] = value;
    }
    else {
        std::cerr << "[Error] setNumber(): Index " << index
            << " out of bounds [0, " << (size - 1) << "]. Action ignored.\n";
    }
}

// Accessor: Safe, bounds-checked retrieval
double NumberArray::getNumber(int index) const {
    if (isValidIndex(index)) {
        return data[index];
    }
    std::cerr << "[Error] getNumber(): Index " << index
        << " out of bounds [0, " << (size - 1) << "]. Returning safe default ("
        << SAFE_DEFAULT << ").\n";
    return SAFE_DEFAULT;
}

// Derived statistics: Minimum value
double NumberArray::getMin() const {
    double minVal = data[0];
    for (int i = 1; i < size; ++i) {
        if (data[i] < minVal) {
            minVal = data[i];
        }
    }
    return minVal;
}

// Derived statistics: Maximum value
double NumberArray::getMax() const {
    double maxVal = data[0];
    for (int i = 1; i < size; ++i) {
        if (data[i] > maxVal) {
            maxVal = data[i];
        }
    }
    return maxVal;
}

// Derived statistics: Arithmetic mean
double NumberArray::getAverage() const {
    double sum = 0.0;
    for (int i = 0; i < size; ++i) {
        sum += data[i];
    }
    return sum / size;
}

// Print: Formatted display of elements
void NumberArray::print() const {
    std::cout << "NumberArray (Size: " << size << "):\n";
    for (int i = 0; i < size; ++i) {
        std::cout << "  [" << i << "] = " << std::fixed << std::setprecision(2) << data[i] << "\n";
    }
}