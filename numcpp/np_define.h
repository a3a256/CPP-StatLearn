#pragma once
#include "np_functions.cpp"
#include <vector>

float* addition_1d();
float** transpose_matrix();
std::vector<std::vector<float>> dot();
float** transform_scaler();
int argmax();
int argmin();
class mean{
    public:
        int axis = 0;
        std::vector<float> mean_val(std::vector<std::vector<float>> arr){
            return mean_calculate(arr, axis);
        }
};
std::vector<float> standard_deviation();
float determinant();
std::vector<std::vector<float>> eye();
std::vector<float> quantiles();
std::vector<float> percentile();
std::vector<int> unique();
int classes();
std::vector<int> bincount();
std::vector<std::vector<int>> square();
std::vector<std::vector<float>> transpose();
float covariance();
std::vector<float> variance();
std::vector<float> quickSort();
std::vector<std::vector<float>> inv();
std::vector<std::vector<std::vector<float>>> qr();
std::vector<float> diag();
std::vector<std::vector<std::vector<float>>> eigenvalues();
bool allclose();