//
// Created by mrzar on 28.06.2024.
//

#ifndef INDIVIDUALV2_QUICKSORT_H
#define INDIVIDUALV2_QUICKSORT_H

#include "Sorter.h"
#include "Sheet.h"

#include <vector>

class Tester;
class QuickSort :
        public Sorter{

public:
    //same constructor as sorter
    QuickSort(Tester* _tester, std::string _name, Sheet* _sheet, int _threads) : Sorter(_tester, _name, _sheet, _threads) {}
    void sort(int start, int end) override;

    void quick_sort(std::vector<int>& tab, int lewy, int ,int start, int end);
};


#endif //INDIVIDUALV2_QUICKSORT_H
