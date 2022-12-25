#include <iostream>
#include "linear_model/linear_regression.cpp"
#include "linear_model/logistic_regression.cpp"
#include <vector>

class LinearRegression{

    private:
        std::vector<std::vector<float>> weights;


    public:

        int epochs = 20;
        float alpha = 0.01;

        void fit(std::vector<std::vector<float>> x, std::vector<std::vector<float>> y){
            weights = optimize(x, y, alpha, epochs);
        }

        std::vector<std::vector<float>> predict(std::vector<std::vector<float>> x){
            return calculate(x, weights);
        }

};



class LogisticRegresssion{

    private:
        std::vector<std::vector<float>> weights;




    public:
        int epochs = 20;
        float alpha = 0.01f;


        void optimize(std::vector<std::vector<float>> x, std::vector<std::vector<int>> y){
            weights = fit(x, y, epochs, alpha);
        }



        std::vector<std::vector<int>> predict(std::vector<std::vector<float>> x){
            return process(x, weights);
        }


};