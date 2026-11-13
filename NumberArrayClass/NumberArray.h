#ifndef NUMBERARRAY_H
#define NUMBERARRAY_H

#include <iostream>

/**
 * Class: NumberArray
 *
 * Purpose:
 * Represents a dynamically allocated collection of double-precision floating-point numbers.
 * The class completely manages the lifecycle of its internal array storage, provides safe,
 * bounds-checked element access, calculates derived statistical metrics (min, max, average),
 * and prints values to the console.
 *
 * Class Invariant:
 * 1. size > 0.
 * 2. data != nullptr, pointing to a contiguous dynamically allocated block of 'size' doubles.
 * 3. Valid element indexes are strictly within the range [0, size - 1].
 * 4. The NumberArray object solely owns the dynamic array pointed to by 'data' and is
 *    responsible for releasing it exactly once upon object destruction.
 */
class NumberArray {
public:
    // Default size and safe return value for out-of-bounds access
    static const int DEFAULT_SIZE = 10;
    static constexpr double SAFE_DEFAULT = 0.0;

    /**
     * Purpose: Initializes a NumberArray object with dynamic memory allocation.
     * Input: sizeParam (int) - desired number of elements (defaults to DEFAULT_SIZE).
     * Preconditions: sizeParam > 0. If sizeParam <= 0, DEFAULT_SIZE is used.
     * Postconditions: 'data' points to an allocated array of 'size' elements; all elements
     *                 are initialized to 0.0; class invariant is satisfied.
     * Output: Initialized NumberArray object.
     */
    explicit NumberArray(int sizeParam = DEFAULT_SIZE);

    /**
     * Purpose: Destroys the NumberArray object and deallocates dynamically allocated memory.
     * Input: None.
     * Preconditions: Object is reaching the end of its lifetime.
     * Postconditions: The dynamic array pointed to by 'data' is deallocated using delete[];
     *                 a confirmation message is output to the console.
     * Output: None.
     */
    ~NumberArray();

    // Prevent copying and assignment as designated by the project boundary
    NumberArray(const NumberArray& other) = delete;
    NumberArray& operator=(const NumberArray& other) = delete;

    /**
     * Purpose: Stores a double value at the specified index if within valid bounds.
     * Input: index (int) - the target index; value (double) - the value to store.
     * Preconditions: None.
     * Postconditions: If index is in [0, size - 1], data[index] is updated to value.
     *                 If index is invalid, no state is modified and an error is reported.
     * Output: None.
     */
    void setNumber(int index, double value);

    /**
     * Purpose: Retrieves the double value stored at the specified index.
     * Input: index (int) - the index of the requested value.
     * Preconditions: None.
     * Postconditions: The state of the object remains completely unchanged.
     * Output: double - data[index] if index is valid; SAFE_DEFAULT (0.0) if invalid.
     */
    double getNumber(int index) const;

    /**
     * Purpose: Finds and returns the minimum value in the array.
     * Input: None.
     * Preconditions: Object satisfies class invariant (size > 0).
     * Postconditions: The object state remains unchanged.
     * Output: double - smallest element in the current array.
     */
    double getMin() const;

    /**
     * Purpose: Finds and returns the maximum value in the array.
     * Input: None.
     * Preconditions: Object satisfies class invariant (size > 0).
     * Postconditions: The object state remains unchanged.
     * Output: double - largest element in the current array.
     */
    double getMax() const;

    /**
     * Purpose: Calculates and returns the arithmetic mean of all elements.
     * Input: None.
     * Preconditions: Object satisfies class invariant (size > 0).
     * Postconditions: The object state remains unchanged.
     * Output: double - sum of all elements divided by size.
     */
    double getAverage() const;
    /**
     * Purpose: Displays all stored values in an indexed list format.
     * Input: None.
     * Preconditions: Object satisfies class invariant.
     * Postconditions: The object state remains unchanged; output sent to std::cout.
     * Output: None.
     */
    void print() const;

    /**
     * Purpose: Accessor for the number of elements in the array.
     * Input: None.
     * Preconditions: None.
     * Postconditions: Object state remains unchanged.
     * Output: int - current size.
     */
    int getSize() const { return size; }
private:
    int size;      // Number of elements managed by the object
    double* data;  // Pointer to dynamic internal array storage

    /**
     * Purpose: Helper function to validate index bounds.
     * Input: index (int) - index to test.
     * Output: bool - true if 0 <= index < size, false otherwise.
     */
    bool isValidIndex(int index) const;
};

#endif // NUMBERARRAY_H