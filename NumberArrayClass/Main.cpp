#include "NumberArray.h"
#include <iostream>
#include <random>
#include <cassert>

void printHeader(const std::string& title) {
    std::cout << "\n========================================\n";
    std::cout << title << "\n";
    std::cout << "========================================\n";
}

int main() {
    // ---------------------------------------------------------
    // Test 1: Default Construction & Zero Initialization
    // ---------------------------------------------------------
    printHeader("Test 1: Default Constructor & Zero-Init Check");
    {
        NumberArray defaultArr;
        std::cout << "Default array created with size: " << defaultArr.getSize() << "\n";
        bool allZero = true;
        for (int i = 0; i < defaultArr.getSize(); ++i) {
            if (defaultArr.getNumber(i) != 0.0) {
                allZero = false;
            }
        }
        std::cout << "All elements zero-initialized: " << (allZero ? "PASSED" : "FAILED") << "\n";
    }

    // ---------------------------------------------------------
    // Test 2: Bounds Checking (First, Middle, Last, Invalid)
    // ---------------------------------------------------------
    printHeader("Test 2: Bounds Checking & Safe Handling");
    {
        NumberArray arr(5);
        // Valid boundaries
        arr.setNumber(0, 10.5);   // First
        arr.setNumber(2, 25.0);   // Middle
        arr.setNumber(4, 99.9);   // Last

        std::cout << "Index 0 (expected 10.5): " << arr.getNumber(0) << "\n";
        std::cout << "Index 2 (expected 25.0): " << arr.getNumber(2) << "\n";
        std::cout << "Index 4 (expected 99.9): " << arr.getNumber(4) << "\n";

        // Invalid boundaries
        std::cout << "\nTesting invalid index -1:\n";
        arr.setNumber(-1, 55.0);
        std::cout << "arr.getNumber(-1) returned: " << arr.getNumber(-1) << "\n";

        std::cout << "\nTesting invalid index 5 (one past end):\n";
        arr.setNumber(5, 77.0);
        std::cout << "arr.getNumber(5) returned: " << arr.getNumber(5) << "\n";
    }

    // ---------------------------------------------------------
    // Test 3: Known Dataset Statistics (Hand Calculated)
    // ---------------------------------------------------------
    printHeader("Test 3: Known Dataset Statistics (Hand Verified)");
    {
        // Dataset: { 12.5, -4.0, 8.5, 23.0, 0.0 }
        // Expected Min: -4.0, Max: 23.0, Sum: 40.0, Average: 40.0 / 5 = 8.0
        NumberArray knownArr(5);
        knownArr.setNumber(0, 12.5);
        knownArr.setNumber(1, -4.0);
        knownArr.setNumber(2, 8.5);
        knownArr.setNumber(3, 23.0);
        knownArr.setNumber(4, 0.0);

        knownArr.print();
        std::cout << "Calculated Min (Expected -4.00): " << knownArr.getMin() << "\n";
        std::cout << "Calculated Max (Expected 23.00): " << knownArr.getMax() << "\n";
        std::cout << "Calculated Avg (Expected 8.00):  " << knownArr.getAverage() << "\n";
    }

    // ---------------------------------------------------------
    // Test 4: Single-Element Array Edge Case
    // ---------------------------------------------------------
    printHeader("Test 4: Single-Element Array Edge Case (Size = 1)");
    {
        NumberArray singleArr(1);
        singleArr.setNumber(0, -42.75);
        std::cout << "Array value: " << singleArr.getNumber(0) << "\n";
        std::cout << "Min (Expected -42.75): " << singleArr.getMin() << "\n";
        std::cout << "Max (Expected -42.75): " << singleArr.getMax() << "\n";
        std::cout << "Avg (Expected -42.75): " << singleArr.getAverage() << "\n";
    }

    // ---------------------------------------------------------
    // Test 5: Random Dataset Reasonableness Checks
    // ---------------------------------------------------------
    printHeader("Test 5: Random Dataset Reasonableness Check");
    {
        const int RND_SIZE = 20;
        NumberArray rndArr(RND_SIZE);

        std::mt19937 rng(1337); // Fixed seed for repeatability
        std::uniform_real_distribution<double> dist(-100.0, 100.0);

        for (int i = 0; i < RND_SIZE; ++i) {
            rndArr.setNumber(i, dist(rng));
        }

        double rMin = rndArr.getMin();
        double rMax = rndArr.getMax();
        double rAvg = rndArr.getAverage();

        std::cout << "Populated 20 random elements.\n";
        std::cout << "Observed Min: " << rMin << "\n";
        std::cout << "Observed Max: " << rMax << "\n";
        std::cout << "Observed Avg: " << rAvg << "\n";

        std::cout << "Invariant Check (Min <= Avg <= Max): "
            << ((rMin <= rAvg && rAvg <= rMax) ? "PASSED" : "FAILED") << "\n";
    }

    // ---------------------------------------------------------
    // Test 6: Block-Scoped Lifetime & Destructor Verification
    // ---------------------------------------------------------
    printHeader("Test 6: Block-Scoped Destructor Verification");
    std::cout << "Entering nested block...\n";
    {
        NumberArray tempArr(3);
        tempArr.setNumber(0, 1.0);
        std::cout << "Temporary object active inside nested block.\n";
    }
    std::cout << "Exited nested block. Destructor confirmed above.\n";

    printHeader("All Unit Tests Completed");
    return 0;
}