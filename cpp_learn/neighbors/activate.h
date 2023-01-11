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

class KNeighborsRegressor{
    public:
        int n_neighbors = 1;
        KNNRegression knr;

        void fit(std::vector<std::vector<float>> x, std::vector<std::vector<float>> y){
            knr.x = x;
            knr.y = y;
            knr.neighbors = n_neighbors;
        }

        std::vector<std::vector<float>> predict(std::vector<std::vector<float>> pr){
            return knr.predict_vals(pr);
        }
};