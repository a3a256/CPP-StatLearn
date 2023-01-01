#include <iostream>
#include "gaussianNB.cpp"
#include <vector>


class GaussianNB{
    public:
        std::vector<std::vector<float>> means;
        std::vector<std::vector<float>> stds;
        std::vector<std::vector<float>> temp;


        void fit(std::vector<std::vector<float>> x, std::vector<std::vector<float>> y){
            means = gaussiannb_fit_means(x, y, means, temp);
        }
};