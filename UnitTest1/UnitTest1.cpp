#include <iostream>
#include <cassert>
#include <ctime>
#include <iomanip>
#include "../lab6.1.2/FileName.cpp"
#include "pch.h"

using namespace std;

// Functions under test (the ones you provided)

void Create(int* a, const int size, const int Low, const int High, int i = 0) {
    if (i >= size) return;
    a[i] = Low + rand() % (High - Low + 1);
    Create(a, size, Low, High, i + 1);
}

void printArray(const int arr[], int size, int i = 0) {
    if (i >= size) {
        cout << endl;
        return;
    }
    cout << setw(4) << arr[i];
    printArray(arr, size, i + 1);
}

void processArray(int arr[], int size, int& count, int& sum, int i = 0) {
    if (i >= size) return;

    if (arr[i] > 0 || arr[i] % 2 != 0) {
        count++;
        sum += arr[i];
        arr[i] = 0;
    }

    processArray(arr, size, count, sum, i + 1);
}

// Basic Unit Test function
void testFunctions() {
    const int SIZE = 5;
    int testArr[SIZE] = { 2, 3, -1, 4, -5 };
    int count = 0, sum = 0;

    // Test processArray
    processArray(testArr, SIZE, count, sum);

    // Test that processArray correctly counts positive/odd elements
    assert(count == 3);  // Expected count of valid elements is 3 (3, -1, and -5)

    // Test that sum is correct for positive/odd elements
    assert(sum == 3 + -1 + -5);  // Expected sum is -3

    // Test that array has been modified (positive/odd elements set to 0)
    assert(testArr[0] == 2);  // Should remain unchanged (even, positive)
    assert(testArr[1] == 0);  // Was 3, should be 0
    assert(testArr[2] == 0);  // Was -1, should be 0
    assert(testArr[3] == 4);  // Should remain unchanged (even, positive)
    assert(testArr[4] == 0);  // Was -5, should be 0

    cout << "All tests passed!" << endl;
}

int main() {
    srand(time(0));  // Seed the random number generator

    // Run unit tests
    testFunctions();

    return 0;
}

