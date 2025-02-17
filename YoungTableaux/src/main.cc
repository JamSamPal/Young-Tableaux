#include "tableaux.hpp"
#include <iostream>

int main(int argc, char** argv){
    if (argc != 2){
        std::cout << "Please pass the order of the tableaux you wish to generate\n";
        return 0;
    }

    int order = std::stoi(argv[1]);
    YoungTableaux yt(order);
    std::cout << "Number of young diagrams for order " << order << " = " << yt.numberDiagrams_ << "\n";

    return 0;
}