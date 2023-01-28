#include <iostream>
#include <vector>
#include "../../numcpp/np_define.h"


std::vector<std::vector<std::vector<float>>> fit_cov_lda(std::vector<std::vector<float>> x, std::vector<std::vector<int>> y){
    std::vector<int> categories;
    categories = unique(y);
    std::vector<std::vector<std::vector<float>>> cov_matrices;
    std::vector<std::vector<float>> sliced;
    for(int i = 0; i<categories.size(); i++){
        for(int j = 0; j<y.size(); j++){
            if(y[j][0] == categories[i]){
                sliced.push_back(x[j]);
            }
        }
        cov_matrices.push_back(cov(sliced));
        std::vector<std::vector<float>>().swap(sliced);
    }

    std::vector<int>().swap(categories);

    return cov_matrices;
}

std::vector<std::vector<float>> fit_mean_lda(std::vector<std::vector<float>> x, std::vector<std::vector<int>> y){
    std::vector<int> categories;
    categories = unique(y);
    std::vector<std::vector<float>> means;
    std::vector<std::vector<float>> sliced;
    for(int i = 0; i<categories.size(); i++){
        for(int j = 0; j<y.size(); j++){
            if(y[j][0] == categories[i]){
                sliced.push_back(x[j]);
            }
        }
        means.push_back(mean_calculate(sliced, (int)0));
        std::vector<std::vector<float>>().swap(sliced);
    }
    std::vector<int>().swap(categories);

    return means;
}