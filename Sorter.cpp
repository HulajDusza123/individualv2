#include "Sorter.h"
#include "Tester.h"
#include <algorithm>
#include <thread>
#include <functional>
#include <fstream>

void Sorter::runSort()
{
    timer.Start();
    size_t numThreads = num_of_threads;
    size_t chunkSize = sheet->getData().size() / numThreads;

    std::vector<std::thread> threads;

    for (size_t i = 0; i < numThreads; ++i) {
        size_t start = i * chunkSize;
        size_t end = (i == numThreads - 1) ? sheet->getData().size() : (i + 1) * chunkSize;
        // threads.emplace_back(&Sorter::sort,this, start, end); // pass 'this' pointer explicitly

        auto data = sheet->getData();

        threads.emplace_back([this, start, end, &data]() {
            sort((int)(start), (int)(end)-1);
        });
    }

    for (auto& t : threads) {
        t.join();
    }

    for (size_t i = 1; i < numThreads; ++i) {
        std::inplace_merge(sheet->getData().begin(),
                           sheet->getData().begin() + i * chunkSize,
                           sheet->getData().begin() +
                           ((i + 1 == numThreads) ? sheet->getData().size()-1 : (i + 1) * chunkSize));
    }

    timer.Stop();

    sheet->setName(getName());
    tester->addResults(sheet);
    view();
    std::cout << "Time: " << timer.GetTime().count() << "ms" << std::endl;
    exportToFile("onesheet.csv");
}
void Sorter::view(){
    std::cout<<getName()<<std::endl;
    for (int i : sheet->getData()) {
        std::cout<<i<<" ";
    }
}
void Sorter::exportToFile(std::string filename){
    std::ofstream file;
    file.open(filename);
    file<<getName()<<std::endl;
    for (int i : sheet->getData()) {
        file<<i<<std::endl;
    }
    file.close();
}