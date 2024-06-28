#include "Sheet.h"
#include <iostream>
//copy constructor
Sheet::Sheet(const Sheet& _sheet) {
    name = _sheet.getName();
    //copy the cells
    for(int i=0;i<_sheet.data.size();i++) {
        data.push_back(_sheet.data[i]);
    }
}
//copy assignment operator
Sheet& Sheet::operator=(const Sheet& _sheet) {
    if(this == &_sheet) {
        return *this;
    }
    name = _sheet.getName();
    //copy the cells
    for(int i=0;i<_sheet.data.size();i++) {
        data.push_back(_sheet.data[i]);
    }
    return *this;
}
Sheet::Sheet() {
    int temp = 5;
}
void Sheet::view() {
    std::cout << "Sheet: " << name << std::endl;
    for (int i = 0; i < data.size(); i++) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}