#include "tableaux.hpp"
#include <iostream>
YoungTableaux::YoungTableaux(const int &order):order_(order){}

void YoungTableaux::DrawYoungTableau(const std::vector<int> &partitionList){
    std::cout << numberDiagrams_ << "\n";
    for (const int length : partitionList){
        for (int i = 0; i < length; i++){
            std::cout << "□";
        }
        if (length != 0){
        std::cout << "\n";
        }
    }
    std::cout << "\n";
}

void YoungTableaux::GeneratePartitions(){
    std::vector<int> partitionList(order_);
    int currIndex = 0;
    partitionList[currIndex] = order_;

    while (true){
        numberDiagrams_++;
        DrawYoungTableau(partitionList);

        while (currIndex >= 0 && partitionList[currIndex] ==1){
            currIndex--;
        }

        if (currIndex < 0){return;}

        int curr_value = partitionList[currIndex];
        partitionList[currIndex]--;
        while (partitionList[currIndex+1] + 1 >= curr_value){
            currIndex++;
        }
        partitionList[currIndex+1]++;
        currIndex++;
    }
}



