//
// Created by mrzar on 28.06.2024.
//

#include "Menu.h"
#include <iostream>
#include "Basic.h"

void Menu::display(){
    int i = 1;
    for (std::string option : options) {
        std::cout<<"["<<i++<<"] " << option << std::endl;
    }
}
int Menu::getChoice(){
    return askForInt(1, options.size());
}