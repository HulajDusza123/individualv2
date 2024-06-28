//
// Created by mrzar on 28.06.2024.
//

#include "Launcher.h"
#include "Sheet.h"
#include "Sorter.h"
#include "QuickSort.h"
#include "BubbleSort.h"
#include "MergeSort.h"
#include <iostream>

Launcher::~Launcher(){
    for(Sheet* s : sheets){
        delete s;
    }
    for(Sorter* s : sortersList){
        delete s;
    }
}
void Launcher::run() {
    if(sorters.size() == 0){
        throw std::runtime_error("No sorters choosen to run");
        return;
    }
    if (threads.size() == 0) {
    throw std::runtime_error("No threads choosen to run");
    return;
}
if (sheets.size() == 0) {
    throw std::runtime_error("No data choosen to run");
    return;
}
if(sorters.size() != threads.size() || sorters.size() != sheets.size() || threads.size() != sheets.size()) {
    throw std::runtime_error("Different number of sorters, threads and data");
    return;
}
    Sorter* temp;
    Sheet* tempSheet;
    for (int i = 0; i < sorters.size(); i++) {
        temp = nullptr;
        tempSheet = nullptr;
        switch (sorters[i]){
            case 1:
                tempSheet = new Sheet(*(sheets[i]));
                temp = new BubbleSort(tester, (std::string)("BubbleSort"), tempSheet,threads.at(i));
                sortersList.push_back(temp);
                break;
            case 2:
                tempSheet = new Sheet(*(sheets[i]));
                temp = new QuickSort(tester, (std::string)("QuickSort"), tempSheet,threads.at(i));
                sortersList.push_back(temp);
                break;
            case 3:
                tempSheet = new Sheet(*(sheets[i]));
                temp = new MergeSort(tester, (std::string)("MergeSort"), tempSheet,threads.at(i));
                sortersList.push_back(temp);
                break;
        }
    }
    for (Sorter* s : sortersList) {
        s->runSort();
    }
}