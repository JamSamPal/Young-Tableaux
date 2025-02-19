#include "tableaux.hpp"
#include <iostream>
#include <fstream>
#include <cmath>
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

void YoungTableaux::GenerateRestrictedPartition(int order, int partitions, int currIndex, std::vector<int> partitionList){

    if(partitions==1){
        partitionList[currIndex] = order;
        numberDiagrams_++;
        DrawYoungTableau(partitionList);
        return;
    }

    int maxIndex = 0;
    int minIndex = 0;

    if(currIndex >0){
        maxIndex = std::min(order-partitions+1, partitionList[currIndex-1]);
    }
    else{
        maxIndex = order-partitions+1;
    }

    
    for (int j = maxIndex; j > 0; j--){
        partitionList[currIndex] = j;
        if ((order-j)/(partitions-1) <= j){
            GenerateRestrictedPartition(order-j, partitions-1, currIndex +1, partitionList);
        }
    }

}

void YoungTableaux::GeneratePartitions(){
    std::vector<int> partitionList(order_);
    int currIndex = 0;

    for (int i = 1; i <= order_; i++){
        GenerateRestrictedPartition(order_, i, currIndex, partitionList);
    }
}

void YoungTableaux::SavePartitionNumber(){
    std::ofstream outFile("partitionNumber.bin", std::ios::binary);

    if (outFile.is_open()) {
        outFile.write(reinterpret_cast<char*>(&numberDiagrams_), sizeof(numberDiagrams_));
        
        std::cout << "Integer written to file.\n";

        outFile.close();
    } else {
        std::cerr << "Error opening file for writing.\n";
    }
}



