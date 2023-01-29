#pragma once
#include <iostream>
#include "discriminant_analaysis_algorithms.cpp"
#include <vector>


class LinearDiscriminantAnalysis{
    private:
        std::vector<std::vector<std::vector<float>>> covariances;
        std::vector<std::vector<float>> means;
        std::vector<float> priors;
};