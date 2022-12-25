#include <iostream>
#include "../../numcpp/np_define.h"
#include <vector>

class LinearRegression{
    private:
        std::vector<std::vector<float>> weights;

    public:
        int epochs = 1;
        float alpha = 0.01f;
        

        void fit(std::vector<std::vector<float>> x, std::vector<std::vector<float>> y){
            int rows = x.size();
            int columns = x[0].size();
            std::vector<float> temp;
            float pred;
            float loss;
            for(int i = 0; i<columns; i++){
                temp.push_back(0.00001f);
            }
            weights.push_back(temp);
            std::vector<std::vector<float>> dis;


            for(int i = 0; i<epochs; i++){
                for(int j = 0; j<rows; j++){
                    dis.push_back(x[j]);
                    pred = dot(dis, transpose(weights))[0][0];
                    loss = 2*pred*(pred-y[j][0]);
                    for(int z = 0; z<weights[0].size(); z++){
                        weights[0][z] -= loss*alpha*weights[0][z];
                    }
                }
            }
        }

        std::vector<std::vector<float>> predict(std::vector<std::vector<float>> x){
            std::vector<std::vector<float>> res;
            std::vector<std::vector<float>> dis;
            std::vector<float> pred;
            int pred;
            for(int i = 0; i<x.size(); i++){
                dis.push_back(x[i]);
                pred = dot(dis, transpose(weights))[0];
                res.push_back({pred});
            }

            return res;
        }
};