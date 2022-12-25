#include <iostream>
#include "cpp_learn/activate.h"

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
    test_linear_regression();

    return 0;
}