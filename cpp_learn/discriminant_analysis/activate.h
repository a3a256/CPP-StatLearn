#pragma once
#include <iostream>
#include "discriminant_analaysis_algorithms.cpp"
#include <vector>


class LinearDiscriminantAnalysis{
    private:
        std::vector<std::vector<std::vector<float>>> covariances;
        std::vector<std::vector<float>> means;
        std::vector<float> priors;


    public:
        void fit(std::vector<std::vector<float>> x, std::vector<std::vector<int>> y){
            covariances = fit_cov_lda(x, y);
            means = fit_mean_lda(x, y);
            priors = calculate_piors(y);
        }
};