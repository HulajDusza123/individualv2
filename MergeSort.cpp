//
// Created by mrzar on 28.06.2024.
//

#include "MergeSort.h"
#include "Sheet.h"

#include <iostream>

void MergeSort::merge(std::vector<int>& array, int const left, int const mid,
           int const right)
{
    int const subArrayOne = mid - left + 1;
    int const subArrayTwo = right - mid;

    // Create temp arrays
     std::vector<int> leftArray;
     std::vector<int> rightArray;

     leftArray.reserve(subArrayOne);
     rightArray.reserve(subArrayTwo);

    // Copy data to temp arrays leftArray[] and rightArray[]
    for (auto i = 0; i < subArrayOne; i++)
        leftArray.at(i) = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray.at(j) = array[mid + 1 + j];

    auto indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;

    // Merge the temp arrays back into array[left..right]
    while (indexOfSubArrayOne < subArrayOne
           && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne]
            <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray]
                    = leftArray.at(indexOfSubArrayOne);
            indexOfSubArrayOne++;
        }
        else {
            array[indexOfMergedArray]
                    = rightArray.at(indexOfSubArrayTwo);
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }

    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray]
                = leftArray.at(indexOfSubArrayOne);
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }

    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray]
                = rightArray.at(indexOfSubArrayTwo);
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
}

// begin is for left index and end is right index
// of the sub-array of arr to be sorted
void MergeSort::merge_sort(std::vector<int>& array, int const begin, int const end)
{
    if (begin >= end)
        return;

    int mid = begin + (end - begin) / 2;
    merge_sort(array, begin, mid);
    merge_sort(array, mid + 1, end);
    merge(array, begin, mid, end);
}

// UTILITY FUNCTIONS
// Function to print an array
void printArray(int A[], int size)
{
    for (int i = 0; i < size; i++)
        std::cout << A[i] << " ";
    std::cout << std::endl;
}

void MergeSort::sort(int start, int end) {
    merge_sort(sheet->getData(), start, end);
}