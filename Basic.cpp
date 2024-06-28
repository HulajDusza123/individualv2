#include <iostream>
#include "Basic.h"

int askForInt(int min, int max) {
    int option;
    while (!(std::cin >> option) || option < min || option > max) {
        std::cout << "Wrong input" << std::endl;
        std::cin.clear();
        std::cin.ignore(100, '\n');
    }
    return option;
}
bool askForBool() {
    char option;
    while (!(std::cin >> option) || (option != 'y' && option != 'n')|| (option != 'Y' && option != 'N')) {
        std::cout << "Wrong input" << std::endl;
        std::cin.clear();
        std::cin.ignore(100, '\n');
    }
    return option == 'y';
}