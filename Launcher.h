//
// Created by mrzar on 28.06.2024.
//

#ifndef INDIVIDUALV2_LAUNCHER_H
#define INDIVIDUALV2_LAUNCHER_H

#include "Sheet.h"
#include "Sorter.h"
#include "QuickSort.h"

#include <vector>
#include <iostream>

class Tester;
class Launcher {
private:
    Tester* tester;
    std::vector<Sheet*> sheets;
    std::vector<int> sorters;
    std::vector<Sorter*> sortersList;
    std::vector<int> threads;

public:
    //copy constructor deleted
    Launcher(const Launcher& other) = delete;
    //copy assignment operator deleted
    Launcher& operator=(const Launcher& other) = delete;
    ~Launcher();
    void addTester(Tester* _tester) { tester = _tester; }
    //void to add sheet
    void addSheet(Sheet* sheet) { sheets.push_back(sheet); }
    //void to add algorithm
    void addSorter(int algorithm) { sorters.push_back(algorithm); }
    void addThreads(int _threads) { if (_threads > 0 && _threads <= 8) threads.push_back(_threads); else std::cout << "Wrong number of threads" << std::endl; }
    void run();
};


#endif //INDIVIDUALV2_LAUNCHER_H
