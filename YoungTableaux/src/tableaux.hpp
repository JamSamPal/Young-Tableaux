#ifndef ABAB1D21_1DED_4DE8_8D47_7009748F2982
#define ABAB1D21_1DED_4DE8_8D47_7009748F2982

#include <vector>
class YoungTableaux{
    public:
    YoungTableaux(const int &order);
    void GeneratePartitions();
    void SavePartitionNumber();
    int numberDiagrams_;

    private:
    void DrawYoungTableau(const std::vector<int> &partitionList);
    void GenerateRestrictedPartition(int order, int partitions, int currIndex, std::vector<int> partitionList);
    int order_;
};

#endif /* ABAB1D21_1DED_4DE8_8D47_7009748F2982 */
