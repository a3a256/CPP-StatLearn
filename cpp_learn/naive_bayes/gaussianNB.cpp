#include <iostream>
#include "../../numcpp/np_define.h"
#include <vector>
#include <math.h>


std::vector<std::vector<float>> gaussiannb_fit_means(std::vector<std::vector<float>> x, std::vector<std::vector<int>> y, std::vector<std::vector<float>> means, std::vector<std::vector<float>> temp){
    std::vector<int> unique_classes;
    mean mn;
    unique_classes = unique(y);
    for(int i = 0; i<unique_classes.size(); i++){
        for(int j = 0; j<x.size(); j++){
            if(unique_classes[i] == y[j][0]){
                temp.push_back(x[j]);
            }
        }
        means.push_back(mn.mean_val(temp));

        std::vector<std::vector<float>>().swap(temp);
    }

    std::vector<int>().swap(unique_classes);
    return means;
}

std::vector<std::vector<float>> gaussiannb_fit_stds(std::vector<std::vector<float>> x, std::vector<std::vector<int>> y, std::vector<std::vector<float>> stds, std::vector<std::vector<float>> temp){
    std::vector<int> unique_classes;
    unique_classes = unique(y);
    for(int i = 0; i<unique_classes.size(); i++){
        for(int j = 0; j<x.size(); j++){
            if(unique_classes[i] == y[j][0]){
                temp.push_back(x[j]);
            }
        }
        stds.push_back(standard_deviation(temp));

        std::vector<std::vector<float>>().swap(temp);
    }
    std::vector<int>().swap(unique_classes);
    return stds;
}


std::vector<std::vector<int>> gaussiannb_predict(std::vector<std::vector<float>> x, std::vector<std::vector<int>> y, std::vector<std::vector<float>> means, std::vector<std::vector<float>> stds){
    std::vector<std::vector<int>> probabilities;
    std::vector<float> proba;
    std::vector<int> unique_classes;
    float a;
    unique_classes = unique(y);
    for(int i = 0; i<x.size(); i++){
        for(int j = 0; j<unique_classes.size(); j++){
            a = 1.0f;
            for(int p = 0; x[0].size(); p++){
                a *= 1/sqrt(2*M_PI*pow(stds[j][p], 2))*exp((-0.5f)*pow(((x[i][p] - means[j][p])/stds[j][p]), 2));
            }
            proba.push_back(a);
        }
        probabilities.push_back({argmax(proba)});
    }

    return probabilities;
}