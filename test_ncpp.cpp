#include <iostream>
#include "numcpp/np_define.h"

void test_qr(){
    std::vector<std::vector<float>> arr {{2, -2, 18}, {2, 1, 0}, {1, 2, 0}};
    std::vector<std::vector<float>> q;
    std::vector<std::vector<float>> r;
    std::vector<std::vector<std::vector<float>>> q_r;
    q_r = qr(arr);
    q = q_r[0];
    r = q_r[1];
    for(int i = 0; i<q.size(); i++){
        for(int j = 0; j < q[0].size(); j++){
            std::cout << q[i][j] << " ";
        }
        std::cout << "\n";
    }
}

void test_feats(){
    std::vector<std::vector<float>> arr {{1.2f, 1.6f, 2.7f}, {3.1f, 8.4f, 5.7f}, {2.1f, 2.5f, 6.7f}};
    for(int i = 0; i<arr.size(); i++){
        for(int j = 0; j < arr[0].size(); j++){
            std::cout << arr[i][j] << " ";
        }
        std::cout << "\n";
    }

    arr = inv(arr);

    for(int i = 0; i<arr.size(); i++){
        for(int j = 0; j < arr[0].size(); j++){
            std::cout << arr[i][j] << " ";
        }
        std::cout << "\n";
    }
}

void test_inv(){
    std::vector<std::vector<float>> arr {{1.2f, 1.6f, 2.7f}, {3.1f, 8.4f, 5.7f}, {2.1f, 2.5f, 6.7f}};
    std::vector<std::vector<float>> inverse;
    inverse = inv(arr);
    for(int i = 0; i<inverse.size(); i++){
        for(int j = 0; j < inverse[0].size(); j++){
            std::cout << inverse[i][j] << " ";
        }
        std::cout << "\n";
    }
}

void test_det(){
    std::vector<std::vector<float>> arr {{1.2f, 1.6f, 2.7f}, {3.1f, 8.4f, 5.7f}, {2.1f, 2.5f, 6.7f}};
    float dt = determinant(arr);
    std::cout << dt << "\n";
}

void test_cov(){
    std::vector<std::vector<float>> arr {{5.1f, 6.5f}, {8.9f, 3.4f}, {9.9f, 12.0f}};
    std::vector<std::vector<float>> res;
    res = cov(arr);

    for(int i = 0; i<res.size(); i++){
        for(int j = 0; j<res[0].size(); j++){
            std::cout << res[i][j] << ' ';
        }
        std::cout << "\n";
    }
    // std::cout << "\n";
}

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
    test_qr();
    return 0;
}