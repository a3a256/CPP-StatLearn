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

        int epochs = 20;
        float alpha = 0.01;

        void fit(std::vector<std::vector<float>> x, std::vector<std::vector<float>> y){
            weights.linear_weights = optimize(x, y, alpha, epochs);
        }

        std::vector<std::vector<float>> predict(std::vector<std::vector<float>> x){
            return calculate(x, weights.linear_weights);
        }

};



class LogisticRegresssion{

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