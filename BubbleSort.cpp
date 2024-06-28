//
// Created by mrzar on 28.06.2024.
//

#include "BubbleSort.h"

void BubbleSort::sort(int start, int end) {
    bubble_sort(sheet->getData());
}

void BubbleSort::bubble_sort(std::vector<int> &tab)
{
    int n = tab.size();
    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n-i-1; j++)
        {
            if(tab[j]>tab[j+1])
            {
                std::swap(tab[j], tab[j+1]);
            }
        }
    }
}