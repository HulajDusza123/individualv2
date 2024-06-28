//
// Created by mrzar on 28.06.2024.
//

#ifndef INDIVIDUALV2_SORTER_H
#define INDIVIDUALV2_SORTER_H

#include <string>
#include "Sheet.h"
#include "Timer.h"

class Tester;
class Sorter
{
protected:
    std::string name;
    Sheet* sheet;
    int num_of_threads;
    Tester* tester;
    Timer timer;

public:
    Sorter(Tester* _tester, std::string _name, Sheet* _sheet, int _threads) {
        tester = _tester;
        name = _name;
        sheet = _sheet;
        num_of_threads = _threads;
    }
    //copy constructor deleted
    Sorter(const Sorter& other) = delete;
    //copy assignment operator deleted
    Sorter& operator=(const Sorter& other) = delete;
    virtual void sort(int start, int end) = 0;
    void runSort();
    std::string getName() { return sheet->getName() + " " + name+ " threads: " + std::to_string(num_of_threads) + ", Time: " + std::to_string(timer.GetTime().count()) +"us"; }
    void view();
    void Sorter::exportToFile(std::string filename);
};


#endif //INDIVIDUALV2_SORTER_H
