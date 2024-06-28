#include "Tester.h"
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <fstream>

#include "Basic.h"
#include "Sheet.h"
#include "Menu.h"
#include "Launcher.h"


Tester::Tester() {

    //create templates
    Sheet* temp = nullptr;
    do temp = new Sheet(); while (temp == nullptr);
    templates.push_back(temp);
    templates[0]->setName("End to back");
    temp = nullptr;
    do temp = new Sheet(); while (temp == nullptr);
    templates.push_back(temp);
    templates[0]->setName("Partially sorted");
    temp = nullptr;
    do temp = new Sheet(); while (temp == nullptr);
    templates.push_back(temp);
    templates[0]->setName("Random");
    initData();
    launcher.addTester(this);
}
Tester::~Tester() {
    for (int i = 0; i < templates.size(); i++) {
        delete templates[i];
    }
    for(int i = 0; i < results.size(); i++) {
        delete results[i];
    }
}
void Tester::initData() {
    //data from back to front
    for (int i = 99999; i >= 0; i--) {
        templates[0]->addData(i);
    }
    //partially sorted data
    for (int i = 0; i < 100000; i++) {
        if (i % 2 == 0) {
            templates[1]->addData(i);
        }
        else {
            templates[1]->addData(100000 - i);
        }
    }
    //data random
    srand(time(NULL));
    for (int i = 0; i < 100000; i++) {
        templates[2]->addData(i);
    }
    for (int i = 0; i < 1000000; i++) {
        int a = rand() % 100000;
        int b = rand() % 100000;
        templates[2]->swapData(a, b);
    }
}
void Tester::menu() {
    //main manu options
    Menu main_menu({
                           "Add algorythm to the test",
                           "Add data to test",
                           "Choose how many threads you want to use",
                           "Run test",
                           "Exit"
                   });

    //sorting algorythm options
    Menu sort_menu({
                           "BubbleSort",
                           "QuickSort",
                           "MergeSort",
                           "Back"
                   });

    //data options
    Menu data_menu({
                           "From the back",
                           "Patrially sorted",
                           "Random"
                           //"[4] Upload from file"
                           "Back"
                   });

    int option;
    do {
        main_menu.display();
        option = main_menu.getChoice();
        int option2;
        int option3;
        Sheet* temp;
        std::string _data_name;

        switch (option) {
            case 1:
                sort_menu.display();
                option2 = sort_menu.getChoice();

                if (option2 != (sort_menu.size())) {
                    launcher.addSorter(option2);
                }
                break;
            case 2:
                data_menu.display();
                option3 = data_menu.getChoice();
                if (option3 == (data_menu.size())) break;
                temp = nullptr;
                do {
                    temp = new Sheet();
                } while (temp == nullptr);

                if (option3 == 4) {
                    //reading from file
                }
                else *temp = *(templates[option3]);

                launcher.addSheet(temp);

                break;
            case 3:
                //choose how many threads you want to use for every test
                std::cout << "Enter the number of threads you want to use for test (1-8)" << std::endl;
                launcher.addThreads(askForInt(1, 8));
                break;
            case 4:
                try {
                    launcher.run();
                    saveResults();
                }
                catch (const std::exception& e) {
                    std::cout << e.what() << std::endl;
                }
                break;
            case 5:

                break;
        }
    } while (option != (main_menu.size()));
}
//fuction to save results to file, sheets are saved in different columns
void Tester::saveResults() {
    std::ofstream file;
    file.open("results.csv");
    for (int i = 0; i < results.size(); i++) {
        file << results[i]->getName()<<";";
        if(i == results.size() - 1) file << std::endl;
    }

    for (int i = 0; i < results[0]->getData().size(); i++) {
        for (int j = 0; j < results.size(); j++) {
            file << results[j]->getData()[i] << ";";
        }
        file << std::endl;
    }
    file.close();
}