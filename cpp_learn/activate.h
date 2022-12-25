#include <iostream>
#include "linear_model/linear_regression.cpp"
#include <vector>

class LinearRegression{

    private:
        std::vector<std::vector<float>> weights;


    public:

        int epochs;
        float alpha;

        void fit();

        std::vector<std::vector<float>> predict();

};