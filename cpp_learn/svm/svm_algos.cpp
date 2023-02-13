#include <iostream>
#include <vector>
#include <math.h>
#include "../../numcpp/np_define.h"


class SGDSVC{
    private:
        std::vector<std::vector<float>> weights;
        float lr;


    public:

        void fit(std::vector<std::vector<float>> x, std::vector<std::vector<float>> y){
            std::vector<float> temp;
            int i, j;
            for(i = 0; i<x[0].size(); i++){
                temp.push_back(0.001f);
            }
            weights.push_back(temp);
            std::vector<float>().swap(temp);
        }
};