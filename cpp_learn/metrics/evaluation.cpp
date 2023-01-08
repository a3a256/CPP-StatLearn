#include <iostream>
#include <vector>
// #include "../../numcpp/np_define.h"
// #ifndef mean_calculate();
// #define mean_calculate();
// #endif

float mean_squared_error(std::vector<std::vector<float>> y_pred, std::vector<std::vector<float>> y_test){
    float _sum = 0.0f;
    for(int i = 0; i<y_pred.size(); i++){
        _sum += pow(abs(y_pred[i][0] - y_test[i][0]), 2);
    }
    return _sum/(float)y_pred.size();
}