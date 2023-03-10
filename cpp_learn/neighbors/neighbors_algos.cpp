#pragma once
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

bool present_classify(std::map<int, int> dict, int target){
    for(std::map<int, int>::iterator it = dict.begin(); it != dict.end(); ++it){
        if(it->first == target){
            return true;
        }
    }
    return false;
}

int frequent_class(std::map<int, int> dict){
    int _max = 0;
    for(std::map<int, int>::iterator it = dict.begin(); it != dict.end(); ++it){
        if(it->second > _max){
            _max = it->second;
        }
    }
    for(std::map<int, int>::iterator it = dict.begin(); it != dict.end(); ++it){
        if(it->second == _max){
            return it->first;
        }
    }

    return _max;
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
        int neighbors=1;

        int predict_one(std::vector<float> pred){
            float x_axis;
            float y_axis;
            int first=0;
            int second;
            float d;
            std::map<int, int> classes;
            std::map<float, std::vector<int>> distances;
            std::map<int, int> classify;
            std::vector<float> dist;
            std::vector<float> temp;
            int t, n;
            int pred_one;
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
                    temp = distances_extract(distances);
                    dist = quickSort(temp);
                    std::vector<float>().swap(temp);
                    t = 0;
                    n = 0;
                    while(t < neighbors){
                        for(int l = 0; l<distances[dist[n]].size(); l++){
                            if(!(present_classify(classify, distances[dist[n]][l]))){
                                classify[distances[dist[n]][l]] = 1;
                            }else{
                                classify[distances[dist[n]][l]] ++;
                            }
                            t ++;
                        }
                        n++;
                    }
                    pred_one = frequent_class(classify);
                    classify.clear();
                    std::vector<float>().swap(dist);
                    distances.clear();
                }
                if(!(present_classify(classes, pred_one))){
                    classes[pred_one] = 1;
                }else{
                    classes[pred_one] ++;
                }
                first ++;
            }
            return frequent_class(classes);
        }

        std::vector<std::vector<int>> predict_vals(std::vector<std::vector<float>> x_pred){
            std::vector<std::vector<int>> pred;
            for(int i = 0; i<x_pred.size(); i++){
                pred.push_back({predict_one(x_pred[i])});
            }
            return pred;
        }
};


class KNNRegression{
    public:
        std::vector<std::vector<float>> y;
        std::vector<std::vector<float>> x;
        int neighbors=1;

        std::vector<std::vector<float>> predict_vals(std::vector<std::vector<float>> to_pred){
            std::vector<std::vector<float>> pred;
            for(int i = 0; i<to_pred.size(); i++){
                pred.push_back({predict_one(to_pred[i])});
            }

            return pred;
        }

    private:

        std::vector<float> extract_distance_keys(std::map<float, std::vector<float>> dict){
            std::vector<float> temp;
            for(std::map<float, std::vector<float>>::iterator it = dict.begin(); it != dict.end(); ++it){
                temp.push_back(it->first);
            }
            dict.clear();
            return temp;
        }

        float predict_one(std::vector<float> x_test){
            std::vector<float> predictions;
            std::map<float, std::vector<float>> distances;
            std::vector<float> dist;
            std::vector<std::vector<float>> temp;
            std::vector<float> vals;
            float distance;
            int k;
            int t;
            for(int j = 0; j < x[0].size(); j++){
                for(int i = 0; i < x.size(); i++){
                    distance = abs(x[i][j] - x_test[j]);
                    distances[distance].push_back(y[i][0]);
                }
                dist = extract_distance_keys(distances);
                k = 0;
                t = 0;
                while(k < neighbors){
                    for(int p = 0; p < distances[dist[t]].size(); p++){
                        vals.push_back(distances[dist[t]][p]);
                        k ++;
                    }
                    t ++;
                }
                temp.push_back(vals);
                predictions.push_back(mean_calculate(temp, (int)0)[0]);
                std::vector<std::vector<float>>().swap(temp);
                std::vector<float>().swap(vals);
                distances.clear();
                std::vector<float>().swap(dist);
            }
            temp.push_back(predictions);

            return mean_calculate(temp, (int)0)[0];
        }
};