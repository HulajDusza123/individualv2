//
// Created by mrzar on 28.06.2024.
//

#ifndef INDIVIDUALV2_MERGESORT_H
#define INDIVIDUALV2_MERGESORT_H

#include "Sorter.h"
#include "Sheet.h"

#include <vector>

class Tester;
class MergeSort : public Sorter{

public:
    //same constructor as sorter
    MergeSort(Tester* _tester, std::string _name, Sheet* _sheet, int _threads) : Sorter(_tester, _name, _sheet, _threads) {}
    void sort(int start, int end) override;
    void MergeSort::merge(std::vector<int>& array, int const left, int const mid, int const right);
    void MergeSort::merge_sort(std::vector<int>& array, int const begin, int const end);
};


#endif //INDIVIDUALV2_MERGESORT_H
