//
// Created by mrzar on 28.06.2024.
//

#ifndef INDIVIDUALV2_BUBBLESORT_H
#define INDIVIDUALV2_BUBBLESORT_H

#include "Sorter.h"
#include "Sheet.h"

#include <vector>

class Tester;
class BubbleSort: public Sorter{

        public:
        //same constructor as sorter
        BubbleSort(Tester* _tester, std::string _name, Sheet* _sheet, int _threads) : Sorter(_tester, _name, _sheet, _threads) {}
        static int compare(const void* a, const void* b);
        void sort(int start, int end) override;

        void bubble_sort(std::vector<int>& tab);

};


#endif //INDIVIDUALV2_BUBBLESORT_H
