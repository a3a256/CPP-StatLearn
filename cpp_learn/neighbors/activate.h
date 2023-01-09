#pragma once
#include <iostream>
#include <vector>
#include "neighbors_algos.cpp"


class KNeighborsClassifier{
    public:
        int n_neighbors = 1;
        KNNPredict knn;


        void fit(std::vector<std::vector<float>> x, std::vector<std::vector<int>> y){
            knn.neighbors = n_neighbors;
            knn.x = x;
            knn.y = y;
        }

        std::vector<std::vector<int>> predict(std::vector<std::vector<float>> x){
            return knn.predict_vals(x);
        }
};