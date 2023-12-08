#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <utility>
#include <algorithm>
#include "../../numcpp/np_define.h"

/*
Initialise centroids, in this case I took k-first samples out of the training dataset
*/

std::vector<std::vector<float>> initialise(std::vector<std::vector<float>> x, int k){
    std::vector<std::vector<float>> weights;
    int i;
    for(i=0; i<k; i++){
        weights.push_back(x[i]);
    }
    return weights;
}

/*
Distance |x-y|
*/

float distance(float x, float y){
    return std::abs(x-y);
}

/*
Slice, we slice values, just as if we would do it using ndarray, like x[classified == cur_label, feature number]
for future to return mean values for each feature
So, if n value of classified is equal to label - we add corresponding row to temporary dataset
*/

std::vector<std::vector<float>> slice(int label, int feature, std::vector<std::vector<float>> &vals, std::vector<int> &classified){
    std::vector<std::vector<float>> temp;
    int i;
    for(i=0; i<vals.size(); i++){
        if(classified[i] == label){
            temp.push_back({vals[i][feature]});
        }
    }
    return temp;
}

struct compare{
    inline bool operator() (std::pair<int, int> &a, std::pair<int, int> &b){
        return a.second>b.second;
    }
};

/*
Added classifier below
What it does - it iterates through each row and each feature
We find distance for each value from our sample for each of K centroids for each feature
after finding distance for each feature and sample we find the closest, using argmin(finding the index with the smallest value)
after finding predicted values for each feature we find the most predicted label and accept it as end result for a give sample
*/

std::vector<int> classify(std::vector<std::vector<float>> &x, std::vector<std::vector<float>> &centroids, int n){
    std::vector<int> res;
    std::vector<std::pair<int, int>> lb_clicks;
    std::map<int, int> temp_cluster;
    std::vector<float> distances;
    int i, j, k;
    for(i=0; i<x.size(); i++){
        for(j=0; j<x[i].size(); j++){
            for(k=0; k<n; k++){
                distances.push_back(distance(x[i][j], centroids[k][j]));
            }
            temp_cluster[argmin(distances)]++;
            std::vector<float>().swap(distances);
        }
        for(auto it: temp_cluster){
            lb_clicks.push_back({it.first, it.second});
        }
        std::sort(lb_clicks.begin(), lb_clicks.end(), compare());
        res.push_back(lb_clicks[0].first);
        std::map<int, int>().swap(temp_cluster);
        std::vector<std::pair<int, int>>().swap(lb_clicks);
    }
    return res;
}

std::vector<std::vector<float>> kmeans_fit(std::vector<std::vector<float>> x, int k, int epochs){
    std::vector<std::vector<float>> weight;
    weight = initialise(x, k);
    int i, j, k;
    for(i=0; i<epochs; i++){
    }
    return weight;
}