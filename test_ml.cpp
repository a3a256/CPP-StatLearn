#include <iostream>
#include <iomanip>
#include "cpp_learn/activate.h"
#include "cpp_learn/naive_bayes/activate.h"

void test_gaussiannb(){
    std::vector<std::vector<float>> x {{3.4f, 7.8f}, {2.3f, 6.5f}, {8.9f, 9.0f}, {1.2f, 7.3f}};
    std::vector<std::vector<int>> y {{0}, {1}, {0}, {1}};
    std::vector<std::vector<float>> x_test {{2.6f, 7.1f}};


    GaussianNB gnb;

    gnb.fit(x, y);


    std::vector<std::vector<int>> res;

    res = gnb.predict(x_test, y);


    for(int i = 0; i<res[0].size(); i++){
        std::cout << res[0][i] << "\n";
    }
}

void test_logistic_regression(){
    std::vector<std::vector<float>> x {{3.4f, 7.8f}, {2.3f, 6.5f}, {8.9f, 9.0f}, {1.2f, 7.3f}};
    std::vector<std::vector<int>> y {{0}, {1}, {0}, {1}};
    std::vector<std::vector<float>> x_test {{2.6f, 7.1f}};


    LogisticRegresssion lg;

    lg.epochs = 30;

    lg.optimize(x, y);


    std::vector<std::vector<int>> res;

    res = lg.predict(x_test);


    for(int i = 0; i<res[0].size(); i++){
        std::cout << res[0][i] << "\n";
    }
}

void test_linear_regression(){

    std::vector<std::vector<float>> x {{3.4f, 2.3f}, {2.1f, 3.9f}};
    std::vector<std::vector<float>> y {{6.5f}, {3.8f}};
    std::vector<std::vector<float>> test{{2.9f, 3.2f}};

    LinearRegression lr;

    lr.epochs = 20;

    lr.fit(x, y);

    std::vector<std::vector<float>> res;
    res = lr.predict(test);

    for(int i = 0; i<res[0].size(); i++){
        std::cout<<res[0][i] << "\n";
    }

}




int main(){

    std::cout << "check";

    test_logistic_regression();

    return 0;
}