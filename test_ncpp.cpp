#include <iostream>
#include "numcpp/np_define.h"

void test_std(){
    std::vector<std::vector<float>> arr {{5.1f, 6.5f}, {8.9f, 3.4f}, {9.9f, 12.0f}};
    std::vector<float> res;
    res = standard_deviation(arr);

    for(int i = 0; i<res.size(); i++){
        std::cout << res[i] << ' ';
    }
    std::cout << "\n";
}

void test_mean(){
    mean mn;
    std::vector<std::vector<float>> arr {{5.1f, 6.5f}, {8.9f, 3.4f}, {9.9f, 12.0f}};
    std::vector<float> res;
    res = mn.mean_val(arr);

    for(int i = 0; i<res.size(); i++){
        std::cout << res[i] << ' ';
    }
    std::cout << "\n";
}

void dot_test(){
    std::vector<std::vector<float>> arr1 {{1.2f, 2.3f}, {3.4f, 4.5f}};
    std::vector<std::vector<float>> arr2{{1.3f}, {3.1f}};
    std::vector<std::vector<float>> res;
    res = dot(arr1, arr2);
    for(int i = 0; i<res.size(); i++){
        for(int j = 0; j<res[0].size(); j++){
            std::cout<<res[i][j]<<" ";
        }
        std::cout<<"\n";
    }
}

void t_test(){
    // std::vector<std::vector<float>> arr {{1.2f, 1.3f, 3.4f}, {3.9f, 4.1f, 7.8f}};
    std::vector<std::vector<float>> arr1 {{1.2f, 1.3f, 3.4f, 3.9f, 4.1f, 7.8f}};
    std::vector<std::vector<float>> res;
    res = transpose(arr1);
    for(int i = 0; i<res.size(); i++){
        for(int j = 0; j<res[0].size(); j++){
            std::cout << res[i][j] << " ";
        }
        std::cout << "\n";
    }
}

int main(){
    test_std();
    return 0;
}