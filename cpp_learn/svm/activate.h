#pragma once
#include <iostream>
#include <vector>
#include "svm_algos.cpp"


class SGDSVMClassifier{
    public:
        float lr = 0.01;
        float C = 1;
        int epochs = 20;
        SGDSVC svc;

        void fit(std::vector<std::vector<float>> x, std::vector<std::vector<int>> y){
            svc.fit(x, y, lr, epochs, C);
        }

        std::vector<std::vector<int>> predict(std::vector<std::vector<float>> x){
            return svc.predict(x);
        }
};