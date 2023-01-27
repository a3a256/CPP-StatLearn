#include <iostream>
#include <vector>
#include "../../numcpp/np_define.h"


std::vector<std::vector<std::vector<float>>> fit_cov_lda(std::vector<std::vector<float>> x, std::vector<std::vector<float>> y){
    std::vector<int> categories;
    categories = classes(y);
}