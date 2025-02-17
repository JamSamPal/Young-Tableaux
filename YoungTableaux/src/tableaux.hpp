#ifndef ABAB1D21_1DED_4DE8_8D47_7009748F2982
#define ABAB1D21_1DED_4DE8_8D47_7009748F2982

class YoungTableaux{
    public:
    YoungTableaux(const int &order);
    int CalculateNumberDiagrams(const int &order);
    int order_;
    int numberDiagrams_;
};

#endif /* ABAB1D21_1DED_4DE8_8D47_7009748F2982 */
