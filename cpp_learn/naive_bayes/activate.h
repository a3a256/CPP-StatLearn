#pragma once
#include <iostream>
#include "gaussianNB.cpp"
#include <vector>


class GaussianNB{
    public:
        std::vector<std::vector<float>> means;
        std::vector<std::vector<float>> stds;
        std::vector<std::vector<float>> temp;


        void fit(std::vector<std::vector<float>> x, std::vector<std::vector<int>> y){
            means = gaussiannb_fit_means(x, y, means, temp);
            stds = gaussiannb_fit_stds(x, y, stds, temp);
        }


        std::vector<std::vector<int>> predict(std::vector<std::vector<float>> x){
            return gaussiannb_predict(x, means, stds);
        }
};