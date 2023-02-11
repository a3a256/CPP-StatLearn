#include <iostream>
#include <vector>
#include "../../numcpp/np_define.h"

float accuracy_score(std::vector<std::vector<int>> y_test, std::vector<std::vector<int>> y_pred){
    int real= 0;
    for(int i = 0; i<y_test.size(); i++){
        if(y_test[i][0] == y_pred[i][0]){
            real ++;
        }
    }

    return (float)real/(float)y_test.size();
}

float mean_absolute_error(std::vector<std::vector<float>> y_pred, std::vector<std::vector<float>> y_test){
    float _sum = 0.0f;
    for(int i = 0; i<y_pred.size(); i++){
        _sum += abs(y_pred[i][0] - y_test[i][0]);
    }
    return _sum/(float)y_pred.size();
}

float mean_squared_error(std::vector<std::vector<float>> y_pred, std::vector<std::vector<float>> y_test){
    float _sum = 0.0f;
    for(int i = 0; i<y_pred.size(); i++){
        _sum += pow(abs(y_pred[i][0] - y_test[i][0]), 2);
    }
    return _sum/(float)y_pred.size();
}