#include <iostream>
#include "../../numcpp/np_define.h"
#include <vector>

// Linear Regression

std::vector<std::vector<float>> optimize(std::vector<std::vector<float>> x, std::vector<std::vector<float>> y, float alpha, int epochs){
            int rows = x.size();
            int columns = x[0].size();
            std::vector<float> temp;
            float pred;
            float loss;
            std::vector<std::vector<float>> weights;
            for(int i = 0; i<columns; i++){
                temp.push_back(0.00001f);
            }
            weights.push_back(temp);
            temp.resize(0);
            temp.shrink_to_fit();
            std::vector<std::vector<float>> dis;


            for(int i = 0; i<epochs; i++){
                for(int j = 0; j<rows; j++){
                    dis.push_back(x[j]);
                    pred = dot(dis, transpose(weights))[0][0];
                    loss = 2*pred*(pred-y[j][0]);
                    for(int z = 0; z<weights[0].size(); z++){
                        weights[0][z] -= loss*alpha*weights[0][z];
                    }
                    dis.pop_back();
                }
            }
            dis.resize(0);
            dis.shrink_to_fit();

            return weights;
}

std::vector<std::vector<float>> calculate(std::vector<std::vector<float>> x, std::vector<std::vector<float>> weights){
            std::vector<std::vector<float>> res;
            std::vector<std::vector<float>> dis;
            std::vector<float> pred;
            for(int i = 0; i<x.size(); i++){
                dis.push_back(x[i]);
                pred = dot(dis, transpose(weights))[0];
                res.push_back({pred});
            }

            dis.resize(0);
            dis.shrink_to_fit();

            return res;
        }


// Logistic Regression 


float logistic_regression_calculate(float e){
    float euler = 1/(1-exp(-e));
    return euler;
}


std::vector<std::vector<float>> logistic_regression_fit(std::vector<std::vector<float>> x, std::vector<std::vector<int>> y, int epochs, float alpha){
    std::vector<std::vector<float>> weights;
    std::vector<std::vector<float>> dis;
    std::vector<float> temp;
    int columns, rows;
    rows = x.size();
    columns = x[0].size();
    for(int i = 0; i<columns; i++){
        temp.push_back(0.00001);
    }
    weights.push_back(temp);
    temp.resize(0);
    temp.shrink_to_fit();
    float pred;
    float loss;


    for(int i = 0; i<epochs; i++){
        for(int j = 0; j<rows; j++){
            dis.push_back(x[i]);
            pred = dot(dis, transpose(weights))[0][0];
            pred = logistic_regression_calculate(pred);
            if(y[j][0] == 0){
                loss = 1/(1-pred);
            }else{
                loss = -(1/pred);
            }

            for(int z=0; z<columns; z++){
                weights[0][z] -= alpha*loss*weights[0][z];
            }


            dis.pop_back();




        }
    }


    dis.resize(0);
    dis.shrink_to_fit();



    return weights;

}


std::vector<std::vector<int>> logistic_regression_predict(std::vector<std::vector<float>> x, std::vector<std::vector<float>> weights){
    std::vector<std::vector<int>> res;
    std::vector<std::vector<float>> dis;

    float pred;


    for(int i = 0; i<x.size(); i++){
        dis.push_back(x[i]);
        pred = dot(dis, transpose(weights))[0][0];
        pred = logistic_regression_calculate(pred);

        if(pred>0.5){
            res.push_back({1});
        }else{
            res.push_back({0});
        }

        dis.pop_back();
    }

    dis.resize(0);
    dis.shrink_to_fit();



    return res;
}