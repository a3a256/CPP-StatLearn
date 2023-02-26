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
            covariances = fit_covs(x, y);
            means = fit_means(x, y);
            priors = calculate_piors(y);
        }

        std::vector<std::vector<int>> predict(std::vector<std::vector<float>> x){
            std::vector<std::vector<int>> predicted;
            for(int i = 0; i<x.size(); i++){
                predicted.push_back({predict_lda_one(x[i], means, covariances, priors)});
            }

            return predicted;
        }
};



class QuadraticDiscriminantAnalysis{
    private:
        std::vector<std::vector<std::vector<float>>> covariances;
        std::vector<std::vector<float>> means;
        std::vector<float> priors;


    public:
        void fit(std::vector<std::vector<float>> x, std::vector<std::vector<int>> y){
            covariances = fit_covs(x, y);
            means = fit_means(x, y);
            priors = calculate_piors(y);
        }

        std::vector<std::vector<int>> predict(std::vector<std::vector<float>> x){
            std::vector<std::vector<int>> predicted;
            for(int i = 0; i<x.size(); i++){
                predicted.push_back({predict_qda_one(x[i], means, covariances, priors)});
            }

            return predicted;
        }
};