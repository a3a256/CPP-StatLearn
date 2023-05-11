#include <iostream>
#include <vector>
#include <math.h>
#include "../../numcpp/np_define.h"

bool is_null(std::vector<std::vector<float>> weight){
    int i, j;
    for(i=0; i<weight.size(); i++){
        for(j=0; j<weight[0].size(); j++){
            if(std::isnan(weight[i][j]) || std::isinf(weight[i][j])){
                return false;
            }
        }
    }

    return true;
}


class SGDSVC{
    private:
        std::vector<std::vector<float>> weights;


    public:

        void fit(std::vector<std::vector<float>> x, std::vector<std::vector<int>> y, float lr, int epochs, float C){
            std::vector<float> temp;
            std::vector<std::vector<float>> temp_d;
            std::vector<std::vector<float>> backup;
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
                    std::vector<std::vector<float>>().swap(grad);
                    std::vector<std::vector<float>>().swap(temp_d);
                    std::vector<float>().swap(temp);
                }
            }
        }


        std::vector<std::vector<int>> predict(std::vector<std::vector<float>> x){
            std::vector<std::vector<int>> y;
            std::vector<std::vector<float>> temp;
            float pred;
            for(int i = 0; i<x.size(); i++){
                temp.push_back(x[i]);
                pred = dot(temp, transpose(weights))[0][0];
                if(pred > 0){
                    y.push_back({1});
                }else if(pred < 0){
                    y.push_back({0});
                }

                std::vector<std::vector<float>>().swap(temp);
            }


            return y;
        }
};