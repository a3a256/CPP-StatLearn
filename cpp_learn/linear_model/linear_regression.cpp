#include <iostream>
#include "../../numcpp/np_define.h"
#include <vector>

class LinearRegression{
    private:
        std::vector<std::vector<float>> weights;

    public:
        int epochs = 1;
        

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
                }
            }
        }
};