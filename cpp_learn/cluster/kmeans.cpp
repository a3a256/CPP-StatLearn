#include <iostream>
#include <vector>
#include <cmath>

std::vector<std::vector<float>> initialise(std::vector<std::vector<float>> x, int k){
    std::vector<std::vector<float>> weights;
    int i;
    for(i=0; i<k; i++){
        weights.push_back(x[i]);
    }
    return weights;
}

float distance(float x, float y){
    return std::abs(x-y);
}

std::vector<float> slice(int label, int feature, std::vector<std::vector<float>> &vals, std::vector<float> &classified){
    std::vector<float> temp;
    int i;
    for(i=0; i<vals.size(); i++){
        if(classified[i] == label){
            temp.push_back(vals[i][feature]);
        }
    }
    return temp;
}

std::vector<std::vector<float>> kmeans_fit(std::vector<std::vector<float>> x, int k){
    std::vector<std::vector<float>> weight;
    weight = initialise(x, k);
    return weight;
}