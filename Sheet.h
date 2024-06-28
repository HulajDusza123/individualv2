//
// Created by mrzar on 28.06.2024.
//

#ifndef INDIVIDUALV2_SHEET_H
#define INDIVIDUALV2_SHEET_H

#include <string>
#include <vector>

class Sheet
{
private:
    std::string name;
    std::vector<int> data;
public:
    void setName(std::string _name) { name = _name; }
    std::string getName() const { return name; }
    void addData(int _data) { data.push_back(_data); }
    void swapData(int _index1, int _index2) { std::swap(data[_index1], data[_index2]); }

    Sheet();
    //copy constructor
    Sheet(const Sheet& _sheet);
    //copy assignment operator
    Sheet& operator=(const Sheet& _sheet);
    std::vector<int>& getData() { return data; }
    void view();
};


#endif //INDIVIDUALV2_SHEET_H
