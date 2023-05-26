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

std::vector<std::vector<float>> kmeans_fit(std::vector<std::vector<float>> x, int k){
    std::vector<std::vector<float>> weight;
    weight = initialise(x, k);
    return weight;
}