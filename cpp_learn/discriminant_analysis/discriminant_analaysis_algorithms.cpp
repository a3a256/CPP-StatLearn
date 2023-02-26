#include <iostream>
#include <vector>
#include <math.h>
#include "../../numcpp/np_define.h"


std::vector<std::vector<std::vector<float>>> fit_covs(std::vector<std::vector<float>> x, std::vector<std::vector<int>> y){
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

std::vector<std::vector<float>> fit_means(std::vector<std::vector<float>> x, std::vector<std::vector<int>> y){
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

std::vector<float> calculate_piors(std::vector<std::vector<int>> y){
    std::vector<int> categories_counts;
    categories_counts = bincount(y);
    std::vector<float> priors;
    int length = y.size();
    for(int i = 0; i<categories_counts.size(); i++){
        priors.push_back((float)categories_counts[i]/(float)length);
    }
    return priors;
}

int predict_lda_one(std::vector<float> x, std::vector<std::vector<float>> means, std::vector<std::vector<std::vector<float>>> covariances, std::vector<float>priors){
    std::vector<float> res;
    std::vector<std::vector<float>> mean_temp;
    std::vector<std::vector<float>> temp_x;
    float first, second, end;
    for(int i = 0; i<priors.size(); i++){
        temp_x.push_back(x);
        mean_temp.push_back(means[i]);
        first = dot(dot(mean_temp, inv(covariances[i])), transpose(temp_x))[0][0];
        second = 0.5*(dot(dot(mean_temp, inv(covariances[i])), transpose(mean_temp))[0][0]);
        end = log(priors[i]);
        res.push_back(first + second + end);
    }

    return argmax(res);
}

int predict_qda_one(std::vector<float> x, std::vector<std::vector<float>> means, std::vector<std::vector<std::vector<float>>> covariances, std::vector<float>priors){
    std::vector<float> res;
    std::vector<float> temp;
    std::vector<std::vector<float>> sub2_1;
    std::vector<std::vector<float>> sub2_2;
    int i;
    int j;
    float first, second, third, end;
    for(i=0; i<priors.size(); i++){
        first = (-0.5f)*log(determinant(covariances[i]));
        for(j=0; j<x.size(); j++){
            temp.push_back(x[j] - means[i][j]);
        }
        sub2_1.push_back(temp);
        std::vector<float>().swap(temp);
        sub2_2 = inv(covariances[i]);
        second = (0.5f)*dot(dot(sub2_1, sub2_2), transpose(sub2_1))[0][0];
        third = log(priors[i]);
        end = first + second + third;
        res.push_back(end);
    }
    return argmax(res);
}