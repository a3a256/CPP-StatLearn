#include <iostream>
#include "numcpp/np_define.h"

void test_mean(){
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
    t_test();
    return 0;
}