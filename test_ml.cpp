#include <iostream>
#include <iomanip>
#include "cpp_learn/activate.h"
#include "cpp_learn/naive_bayes/activate.h"
#include "cpp_learn/neighbors/activate.h"
#include "cpp_learn/metrics/activate.h"
#include "cpp_learn/svm/activate.h"
#include "cpp_learn/discriminant_analysis/activate.h"

void test_lg_regression(){
    std::vector<std::vector<float>> x {{3.4f, 7.8f}, {2.3f, 6.5f}, {8.9f, 9.0f}, {1.2f, 7.3f}};
    std::vector<std::vector<float>> y {{0}, {1}, {0}, {1}};
    std::vector<std::vector<float>> x_test {{2.6f, 7.1f}};


    LogisticRegression lg;

    lg.fit(x, y);


    std::vector<std::vector<float>> res;

    res = lg.predict(x_test);


    for(int i = 0; i<res[0].size(); i++){
        std::cout << res[0][i] << "\n";
    }
}


void test_ridge_regression(){
    std::vector<std::vector<float>> x {{3.4f, 2.3f}, {2.1f, 3.9f}};
    std::vector<std::vector<float>> y {{6.5f}, {3.8f}};
    std::vector<std::vector<float>> test{{2.9f, 3.2f}};

    RidgeRegressor rg;

    std::vector<std::vector<float>> res;

    rg.fit(x, y);

    res = rg.predict(test);

    for(int i = 0; i<res.size(); i++){
        for(int j = 0; j<res[0].size(); j++){
            std::cout << res[i][j] << " ";
        }
        std::cout << "\n";
    }
}

void test_quadratic_discriminant_classifier(){
    std::vector<std::vector<float>> x {{3.4f, 7.8f}, {2.3f, 6.5f}, {8.9f, 9.0f}, {1.2f, 7.3f}, {4.5f, 8.1f}, {2.5f, 4.1f}};
    std::vector<std::vector<int>> y {{0}, {1}, {0}, {1}, {0}, {1}};
    std::vector<std::vector<float>> x_test {{2.6f, 7.1f}, {7.9f, 9.9f}};

    QuadraticDiscriminantAnalysis qda;
    qda.fit(x, y);

    std::vector<std::vector<int>> res;

    res = qda.predict(x_test);

    for(int i = 0; i<res.size(); i++){
        std::cout << "Result " << res[i][0] << "\n";
    }

}

void test_logistic_discriminant_classifier(){
    std::vector<std::vector<float>> x {{3.4f, 7.8f}, {2.3f, 6.5f}, {8.9f, 9.0f}, {1.2f, 7.3f}, {4.5f, 8.1f}, {2.5f, 4.1f}};
    std::vector<std::vector<int>> y {{0}, {1}, {0}, {1}, {0}, {1}};
    std::vector<std::vector<float>> x_test {{2.6f, 7.1f}, {7.9f, 9.9f}};

    LinearDiscriminantAnalysis lda;
    lda.fit(x, y);

    std::vector<std::vector<int>> res;

    res = lda.predict(x_test);

    for(int i = 0; i<res.size(); i++){
        std::cout << "Result " << res[i][0] << "\n";
    }

}

void test_svc_classifier(){
    std::vector<std::vector<float>> x {{3.4f, 7.8f}, {2.3f, 6.5f}, {8.9f, 9.0f}, {1.2f, 7.3f}};
    std::vector<std::vector<int>> y {{0}, {1}, {0}, {1}};
    std::vector<std::vector<float>> x_test {{2.6f, 7.1f}};


    SGDSVMClassifier svc;

    svc.fit(x, y);


    std::vector<std::vector<int>> res;

    res = svc.predict(x_test);


    for(int i = 0; i<res[0].size(); i++){
        std::cout << "Result " << res[0][i] << "\n";
    }
}

void test_mae(){
    std::vector<std::vector<float>> y_pred {{1.2f}, {3.4f}, {6.3f}};
    std::vector<std::vector<float>> y_test {{3.9f}, {8.9f}, {1.2f}};

    std::cout << mean_absolute_error(y_pred, y_test);
}

void test_ols_regression(){
    std::vector<std::vector<float>> x {{3.4f, 2.3f}, {2.1f, 3.9f}};
    std::vector<std::vector<float>> y {{6.5f}, {3.8f}};
    std::vector<std::vector<float>> test{{2.9f, 3.2f}};

    LinearRegression lr;

    std::vector<std::vector<float>> res;

    lr.fit(x, y);

    res = lr.predict(test);

    for(int i = 0; i<res.size(); i++){
        for(int j = 0; j<res[0].size(); j++){
            std::cout << res[i][j] << " ";
        }
        std::cout << "\n";
    }
}

void test_accuracy_score(){
    std::vector<std::vector<int>> y1 {{0}, {1}, {1}, {0}, {0}};
    std::vector<std::vector<int>> y2 {{1}, {1}, {1}, {0}, {1}};

    std::cout << accuracy_score(y1, y2) << "\n";
}

void test_mse(){
    std::vector<std::vector<float>> y_pred {{1.2f}, {3.4f}, {6.3f}};
    std::vector<std::vector<float>> y_test {{3.9f}, {8.9f}, {1.2f}};

    std::cout << mean_squared_error(y_pred, y_test);
}

void test_knnr(){

    std::vector<std::vector<float>> x {{3.4f, 2.3f}, {2.1f, 3.9f}};
    std::vector<std::vector<float>> y {{6.5f}, {3.8f}};
    std::vector<std::vector<float>> test{{2.9f, 3.2f}};

    KNeighborsRegressor knnr;

    knnr.n_neighbors = 1;

    knnr.fit(x, y);

    std::vector<std::vector<float>> res;
    res = knnr.predict(test);

    for(int i = 0; i<res[0].size(); i++){
        std::cout<<res[0][i] << "\n";
    }

}

void test_knn_classifier(){
    std::vector<std::vector<float>> x {{3.4f, 7.8f}, {2.3f, 6.5f}, {8.9f, 9.0f}, {1.2f, 7.3f}};
    std::vector<std::vector<int>> y {{0}, {1}, {0}, {1}};
    std::vector<std::vector<float>> x_test {{2.6f, 7.1f}};


    KNeighborsClassifier knn;

    knn.fit(x, y);


    std::vector<std::vector<int>> res;

    res = knn.predict(x_test);


    for(int i = 0; i<res[0].size(); i++){
        std::cout << "Result " << res[0][i] << "\n";
    }
}

// void test_gaussiannb(){
//     std::vector<std::vector<float>> x {{3.4f, 7.8f}, {2.3f, 6.5f}, {8.9f, 9.0f}, {1.2f, 7.3f}};
//     std::vector<std::vector<int>> y {{0}, {1}, {0}, {1}};
//     std::vector<std::vector<float>> x_test {{2.6f, 7.1f}};


//     GaussianNB gnb;

//     gnb.fit(x, y);


//     std::vector<std::vector<int>> res;

//     res = gnb.predict(x_test);


//     for(int i = 0; i<res[0].size(); i++){
//         std::cout << res[0][i] << "\n";
//     }
// }

// void test_logistic_regression(){
//     std::vector<std::vector<float>> x {{3.4f, 7.8f}, {2.3f, 6.5f}, {8.9f, 9.0f}, {1.2f, 7.3f}};
//     std::vector<std::vector<int>> y {{0}, {1}, {0}, {1}};
//     std::vector<std::vector<float>> x_test {{2.6f, 7.1f}};


//     LogisticRegresssion lg;

//     lg.epochs = 30;

//     lg.optimize(x, y);


//     std::vector<std::vector<int>> res;

//     res = lg.predict(x_test);


//     for(int i = 0; i<res[0].size(); i++){
//         std::cout << res[0][i] << "\n";
//     }
// }

void sgd_linear_regression(){

    std::vector<std::vector<float>> x {{3.4f, 2.3f}, {2.1f, 3.9f}};
    std::vector<std::vector<float>> y {{6.5f}, {3.8f}};
    std::vector<std::vector<float>> test{{2.9f, 3.2f}};

    SGDRegression lr;

    lr.epochs = 20;

    lr.fit(x, y);

    std::vector<std::vector<float>> res;
    res = lr.predict(test);

    for(int i = 0; i<res[0].size(); i++){
        std::cout<<res[0][i] << "\n";
    }

}




int main(){

    // std::cout << "check\n";

    test_svc_classifier();

    return 0;
}