#include <iostream>
#include <vector>
#include <math.h>
#include "../../numcpp/np_define.h"


class SGDSVC{
    private:
        std::vector<std::vector<float>> weights;


    public:

        std::vector<std::vector<float>> fit(std::vector<std::vector<float>> x, std::vector<std::vector<int>> y, float lr, int epochs, float C){
            std::vector<float> temp;
            std::vector<std::vector<float>> temp_d;
            std::vector<std::vector<float>> grad;
            int i, j;
            float error, grad_val;
            float hat;
            for(i = 0; i<x[0].size(); i++){
                temp.push_back(0.001f);
            }
            weights.push_back(temp);
            std::vector<float>().swap(temp);

            for(i = 0; i<epochs; i++){
                for(j = 0; j<x.size(); j++){
                    temp_d.push_back(x[j]);
                    hat = dot(temp_d, transpose(weights))[0][0];
                    error = 1 - (float)y[j][0]*hat;
                    if(error <= 0){
                        grad = weights;
                    }else{
                        for(int k = 0; k<x[0].size(); k++){
                            temp.push_back(weights[0][k] - C*(float)y[j][0]*x[j][k]);
                        }
                        grad.push_back(temp);
                    }

                    for(int k = 0; k<x[0].size(); k++){
                        weights[0][k] -= lr*grad[0][k];
                    }
                }
            }


            return weights;
        }
};