#include <iostream>
#include <vector>
#include "../../numcpp/np_define.h"
#include <map>

bool present(std::map<float, std::vector<int>> dict, float target){
    for(std::map<float, std::vector<int>>::iterator it = dict.begin(); it != dict.end(); ++it){
        if(it->first == target){
            return true;
        }
    }
    return false;
}

float distance_calculate(float x1, float y1, float x2, float y2){
    return sqrt(pow(x1-x2, 2) + pow(y1-y2, 2));
}

std::vector<float> distances_extract(std::map<float, std::vector<int>> mp){
    std::vector<float> key;
    for(std::map<float, std::vector<int>>::iterator it = mp.begin(); it != mp.end(); ++it){
        key.push_back(it->first);
    }
    return key;
}

class KNNPredict{
    public:
        std::vector<std::vector<int>> y;
        std::vector<std::vector<float>> x;

        int predict_one(std::vector<float> pred){
            float x_axis;
            float y_axis;
            int first;
            int second;
            float d;
            std::map<float, std::vector<int>> classes;
            std::map<float, std::vector<int>> distances;
            std::map<int, int> classify;
            std::vector<float> dist;
            while(first < x[0].size()-1){
                for(int j = first+1; j<x[0].size(); j++){
                    second = j;
                    x_axis = pred[first];
                    y_axis = pred[second];
                    for(int i = 0; i<x.size(); i++){
                        d = distance_calculate(x_axis, y_axis, x[i][first], x[i][second]);
                        if (!(present(distances, d))){
                            distances[d].push_back(y[i][0]);
                        }else{
                            distances[d].push_back(y[i][0]);
                        }
                    }
                    dist = distances_extract(distances);
                }
            }
            return 0;
        }

        std::vector<std::vector<int>> predict(std::vector<std::vector<float>> x_pred){
            std::vector<std::vector<int>> pred;
            return pred;
        }
};