#pragma once
#include <kmeans.cpp>


class KMeans{
    public:
        int k=1;
        int epochs=20;
        std::vector<int> predicted;

        KMeans(int n){
            k = n;
        }

        std::vector<std::vector<float>> centroids;

        void fit(std::vector<std::vector<float>> &x){
            centroids = kmeans_fit(x, centroids, k, epochs);
        }

        std::vector<std::vector<int>> predict(std::vector<std::vector<float>> &x){
            predicted = classify(x, centroids, k);
            std::vector<std::vector<int>> res;
            for(int i: predicted){
                res.push_back({i});
            }
            std::vector<int>().swap(predicted);
            return res;
        }
};