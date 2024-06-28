//
// Created by mrzar on 28.06.2024.
//

#ifndef INDIVIDUALV2_TESTER_H
#define INDIVIDUALV2_TESTER_H

#include "Sheet.h"
#include "Launcher.h"
#include <vector>


class Tester{
private:
    std::vector<Sheet*> templates;
    std::vector<Sheet*> results;
    Launcher launcher;
public:
    //constructor
    Tester();
    //destructor
    ~Tester();
    //copy constructor deleted
    Tester(const Tester& other) = delete;
    //copy assignment operator deleted
    Tester& operator=(const Tester& other) = delete;

    //fucntin to init tempaltes
    void initData();
    //function to write menu to console
    void menu();
    //fuction to add results
    void addResults(Sheet* _result) { results.push_back(_result); }
    void saveResults();
};


#endif //INDIVIDUALV2_TESTER_H
