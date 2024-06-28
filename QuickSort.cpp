#include "QuickSort.h"
#include <vector>


void QuickSort::quick_sort(std::vector<int> &tab, int lewy, int prawy,int start, int end) {
    int v=tab[(lewy+prawy)/2];
    int i,j;
    i=lewy;
    j=prawy;
    do
    {
        while(tab[i]<v) i++;
        while(tab[j]>v) j--;
        if(i<=j)
        {
            std::swap(tab[i], tab[j]); // swap tab[i] with tab[j]
            i++;
            j--;

        }
    }
    while(i<=j);
    if(j>lewy) quick_sort(tab,lewy, j,start, end);
    if(i<prawy) quick_sort(tab, i, prawy,start, end);
}
void QuickSort::sort(int start, int end){
    quick_sort(sheet->getData(), start,end,start, end);
}