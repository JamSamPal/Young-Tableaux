#include "tableaux.hpp"

YoungTableaux::YoungTableaux(const int &order):order_(order){numberDiagrams_=CalculateNumberDiagrams(order);}

int YoungTableaux::CalculateNumberDiagrams(const int &order){
    if (order < 1){
        return 0;
    }
    else if (order == 1){
        return 1;
    }
    else{
        return CalculateNumberDiagrams(order-1) + (order-1)*CalculateNumberDiagrams(order-2);
    }

}



