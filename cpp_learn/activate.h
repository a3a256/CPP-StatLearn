#pragma once
#include <iostream>
#include "linear_model/linear_regression.cpp"
#include <vector>

// initialise weights

class Weights{
    public:
        std::vector<std::vector<float>> linear_weights;
};

class LinearRegression{
    private:
        Weights weights;

    public:
        void fit(std::vector<std::vector<float>> x, std::vector<std::vector<float>> y){
            weights.linear_weights = ols_predict(x, y);
        }

        std::vector<std::vector<float>> predict(std::vector<std::vector<float>> x){
            return ols_predict(x, weights.linear_weights);
        }
};

class SGDRegression{

    private:
        Weights weights;


    public:

        int epochs = 20;
        float alpha = 0.1;

        void fit(std::vector<std::vector<float>> x, std::vector<std::vector<float>> y){
            weights.linear_weights = optimize(x, y, alpha, epochs);
            for(int i=0; i<weights.linear_weights.size(); i++){
                for(int j = 0; j<weights.linear_weights[i].size(); j++){
                    std::cout << weights.linear_weights[i][j] << " ";
                }

                std::cout << "\n";
            }
        }

        std::vector<std::vector<float>> predict(std::vector<std::vector<float>> x){
            return calculate(x, weights.linear_weights);
        }

};



class SGDLogisticRegresssion{

    private:
        Weights weights;




    public:
        int epochs = 20;
        float alpha = 0.01f;


        void optimize(std::vector<std::vector<float>> x, std::vector<std::vector<int>> y){
            std::vector<float> temple;
            for(int i = 0; i<x[0].size(); i++){
                temple.push_back(0.0001f);
            }
            weights.linear_weights.push_back(temple);
            temple.resize(0);
            temple.shrink_to_fit();
            weights.linear_weights = logistic_regression_fit(x, y, weights.linear_weights, epochs, alpha);
        }



        std::vector<std::vector<int>> predict(std::vector<std::vector<float>> x){
            return logistic_regression_predict(x, weights.linear_weights);
        }


};



class LogisticRegression{

    public:
        std::vector<std::vector<float>> weights;
        int n_iters = 100;


        void fit(std::vector<std::vector<float>> x, std::vector<std::vector<float>> y){
            std::cout << "flag\n";
            weights = lg_regression_fit(x, y, n_iters);
        }


        std::vector<std::vector<float>> predict(std::vector<std::vector<float>> x){
            return lg_predict(x, weights);
        }


};


class RidgeRegressor{
    public:
        std::vector<std::vector<float>> weight;
        float alpha = 0.1;


        void fit(std::vector<std::vector<float>> x, std::vector<std::vector<float>> y){
            weight = ridge_regressor_fit(x, y, alpha);
        }

        std::vector<std::vector<float>> predict(std::vector<std::vector<float>> x){
            return ridge_regressor_predict(x, weight);
        }
};