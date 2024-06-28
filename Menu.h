//
// Created by mrzar on 28.06.2024.
//

#ifndef INDIVIDUALV2_MENU_H
#define INDIVIDUALV2_MENU_H

#include <list>
#include <string>


class Menu {
private:
    std::list<std::string> options;
public:
    Menu(std::list<std::string> _options) { options = _options; }
    void display();
    int getChoice();
    int size() { return options.size(); }
};


#endif //INDIVIDUALV2_MENU_H
