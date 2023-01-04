#include <iostream>
#include <vector>
#include "../../numcpp/np_define.h"
#include <map>

float distance_calculate(float x1, float y1, float x2, float y2){
    return sqrt(pow(x1-x2, 2) + pow(y1-y2, 2));
}

class KNNPredict{
    public:
        std::vector<std::vector<int>> y;
        std::vector<std::vector<float>> x;

        int predict_one(std::vector<std::vector<float>> pred){
            std::vector<float> x_axis;
            std::vector<float> y_axis;
            int first;
            int second;
            std::map<float, std::vector<int>> classes;
            std::map<float, std::vector<int>> distances;
            return 0;
        }

        std::vector<std::vector<int>> predict(std::vector<std::vector<float>> x_pred){
            std::vector<std::vector<int>> pred;
            return pred;
        }
};