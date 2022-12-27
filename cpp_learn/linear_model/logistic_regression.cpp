#include <iostream>
#include "../../numcpp/np_define.h"

std::vector<std::vector<float>> fit(std::vector<std::vector<float>> x, std::vector<std::vector<int>> y, int epochs, float alpha){
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
    float temple;


    for(int i = 0; i<epochs; i++){
        for(int j = 0; j<rows; j++){
            dis.push_back(x[i]);
            pred = dot(dis, transpose(weights))[0][0];
            std::cout << pred;
            temple = calculate(pred);
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

float calculate(float e){
    float euler = 1/(1-exp(-e));
    return euler;
}





std::vector<std::vector<int>> process(std::vector<std::vector<float>> x, std::vector<std::vector<float>> weights){
    std::vector<std::vector<int>> res;
    std::vector<std::vector<float>> dis;

    float pred;


    for(int i = 0; i<x.size(); i++){
        dis.push_back(x[i]);
        pred = dot(dis, transpose(weights))[0][0];
        pred = calculate(pred);

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