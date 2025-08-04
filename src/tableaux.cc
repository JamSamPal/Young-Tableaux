#include "tableaux.hpp"
#include <cmath>
#include <fstream>
#include <iostream>
YoungTableaux::YoungTableaux(const int &order) : order_(order) {}

void YoungTableaux::DrawYoungTableau(const std::vector<int> &partitionList) {
    std::cout << numberDiagrams_ << "\n";
    for (const int length : partitionList) {
        for (int i = 0; i < length; i++) {
            std::cout << "□";
        }
        if (length != 0) {
            std::cout << "\n";
        }
    }
    std::cout << "\n";
}

void YoungTableaux::GeneratePartitions() {

    std::vector<int> partitionList(order_);
    int currIndex = 0;
    // Enumerates the Tableaux with each Tableau being arranged in a vector.
    // E.g. if order = 4. Then we find all the diagrams that partition
    // 4 into 1,2,3 and 4 pieces.
    for (int i = 1; i <= order_; i++) {
        GenerateRestrictedPartition(order_, i, currIndex, partitionList);
    }
}

void YoungTableaux::GenerateRestrictedPartition(int order, int partitions, int currIndex, std::vector<int> partitionList) {

    // Just one partition means we can return
    if (partitions == 1) {
        partitionList[currIndex] = order;
        numberDiagrams_++;
        DrawYoungTableau(partitionList);
        return;
    }

    // To ensure our diagrams are strictly decreasing
    // we cap the max index based on previously added partition
    int maxIndex = 0;

    if (currIndex > 0) {
        maxIndex = std::min(order - partitions + 1, partitionList[currIndex - 1]);
    } else {
        maxIndex = order - partitions + 1;
    }

    for (int j = maxIndex; j > 0; j--) {
        partitionList[currIndex] = j;
        // If this condition is not met the next
        // generated partition will not be strictly
        // decreasing
        if ((order - j) / (partitions - 1) <= j) {
            GenerateRestrictedPartition(order - j, partitions - 1, currIndex + 1, partitionList);
        }
    }
}

void YoungTableaux::SavePartitionNumber() {
    // Needed for python testing
    std::ofstream partition_file("partitionNumber.txt");
    partition_file << numberDiagrams_ << "\n";
}
