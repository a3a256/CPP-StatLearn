#include <iostream>
#include "../../numcpp/np_define.h"
#include <vector>
#include <cmath>

bool present_nulls(std::vector<std::vector<float>> x){
    int i, j;
    for(i=0; i<x.size(); i++){
        for(j=0; j<x[0].size(); j++){
            if(std::isnan(x[i][j]) || std::isinf(x[i][j])){
                return true;
            }
        }
    }
    return false;
}

//OLS Regression

std::vector<std::vector<float>> ols_fit(std::vector<std::vector<float>> x, std::vector<std::vector<float>> y){
    std::vector<std::vector<float>> weights;
    weights = dot(dot(inv(dot(transpose(x), x)), transpose(x)), y);
    return weights;
}

std::vector<std::vector<float>> ols_predict(std::vector<std::vector<float>> x, std::vector<std::vector<float>> weights){
    std::vector<std::vector<float>> res;
    res = dot(x, weights);
    return res;
}

// Linear Regression

std::vector<std::vector<float>> optimize(std::vector<std::vector<float>> x, std::vector<std::vector<float>> y, float alpha, int epochs){
            int rows = x.size();
            int columns = x[0].size();
            std::vector<float> temp;
            float pred;
            float loss;
            std::vector<std::vector<float>> weights;
            for(int i = 0; i<columns; i++){
                temp.push_back(0.01f);
            }
            weights.push_back(temp);
            temp.resize(0);
            temp.shrink_to_fit();
            std::vector<std::vector<float>> dis;
            std::vector<std::vector<float>> backup;


            for(int i = 0; i<epochs; i++){
                for(int j = 0; j<rows; j++){
                    dis.push_back(x[j]);
                    pred = dot(dis, transpose(weights))[0][0];
                    loss = 2*pred*(pred-y[j][0]);
                    for(int z = 0; z<weights[0].size(); z++){
                        weights[0][z] -= loss*alpha*weights[0][z];
                    }
                    dis.pop_back();
                    if(!(present_nulls(weights))){
                        backup = weights;
                    }else{
                        weights = backup;
                        break;
                    }
                }
            }
            dis.resize(0);
            dis.shrink_to_fit();

            return weights;
}

std::vector<std::vector<float>> calculate(std::vector<std::vector<float>> x, std::vector<std::vector<float>> weights){
            std::vector<std::vector<float>> res;
            std::vector<std::vector<float>> dis;
            std::vector<float> pred;
            for(int i = 0; i<x.size(); i++){
                dis.push_back(x[i]);
                pred = dot(dis, transpose(weights))[0];
                res.push_back(pred);
            }

            dis.resize(0);
            dis.shrink_to_fit();

            return res;
        }


// Logistic Regression 


float logistic_regression_calculate(float e){
    float euler = 1/(1-exp(-e));
    return euler;
}


std::vector<std::vector<float>> logistic_regression_fit(std::vector<std::vector<float>> x, std::vector<std::vector<int>> y, std::vector<std::vector<float>> weights, int epochs, float alpha){
    std::vector<std::vector<float>> dis;
    int columns, rows;
    rows = x.size();
    columns = x[0].size();
    long double pred;
    long double loss;


    for(int i = 0; i<epochs; i++){
        for(int j = 0; j<rows; j++){
            dis.push_back(x[j]);
            pred = dot(dis, transpose(weights))[0][0];
            pred = logistic_regression_calculate(pred);
            if(y[j][0] == 0){
                loss = 1/(1-pred);
            }else{
                loss = -(1/pred);
            }

            for(int z=0; z<columns; z++){
                weights[0][z] -= alpha*loss*weights[0][z];
            }


            std::vector<std::vector<float>>().swap(dis);




        }
    }


    std::vector<std::vector<float>>().swap(dis);



    return weights;

}


std::vector<std::vector<int>> logistic_regression_predict(std::vector<std::vector<float>> x, std::vector<std::vector<float>> weights){
    std::vector<std::vector<int>> res;
    std::vector<std::vector<float>> dis;

    float pred;


    for(int i = 0; i<x.size(); i++){
        dis.push_back(x[i]);
        pred = dot(dis, transpose(weights))[0][0];
        pred = logistic_regression_calculate(pred);

        if(pred>0.5){
            res.push_back({1});
        }else{
            res.push_back({0});
        }

        std::vector<std::vector<float>>().swap(dis);
    }

    std::vector<std::vector<float>>().swap(dis);



    return res;
}

// RidgeRegressor


std::vector<std::vector<float>> ridge_regressor_fit(std::vector<std::vector<float>> x, std::vector<std::vector<float>> y, float alpha){
    std::vector<std::vector<float>> weights;
    std::vector<std::vector<float>> identity;
    std::vector<std::vector<float>> first;
    std::vector<std::vector<float>> inverse;
    std::vector<std::vector<float>> second;
    identity = eye(x[0].size());
    int i, j;
    for(i = 0; i<identity.size(); i++){
        for(j = 0; j<identity[0].size(); j++){
            identity[i][j] *= alpha;
        }
    }

    first = dot(transpose(x), x);

    for(i = 0; i<first.size(); i++){
        for(j = 0; j<first[0].size(); j++){
            first[i][j] += identity[i][j];
        }
    }

    inverse = inv(first);
    second = dot(inverse, transpose(x));

    weights = dot(second, y);

    return weights;
}


std::vector<std::vector<float>> ridge_regressor_predict(std::vector<std::vector<float>> x, std::vector<std::vector<float>> weights){
    std::vector<std::vector<float>> res;
    res = dot(x, weights);
    return res;
}

// Logistic Regression _ 1

std::vector<std::vector<float>> lg_equation(std::vector<std::vector<float>> x, std::vector<std::vector<float>> weights){
    std::vector<std::vector<float>> res;
    res = dot(x, transpose(weights));
    for(int i = 0; i<res.size(); i++){
        res[i][0] = exp(res[i][0])/(1+exp(res[i][0]));
    }

    return res;
}

std::vector<std::vector<float>> lg_regression_fit(std::vector<std::vector<float>> x, std::vector<std::vector<float>> y, int n_iters){
    std::vector<std::vector<float>> weights;
    std::vector<std::vector<float>> inv_bracket;
    std::vector<std::vector<float>> equation;
    std::vector<std::vector<float>> iden;
    std::vector<std::vector<float>> g;
    std::vector<float> temp;
    int i, j, k;
    for(i = 0; i<x[0].size(); i++){
        temp.push_back(1e-2);
    }
    std::vector<std::vector<float>> back_up;

    weights.push_back(temp);

    back_up = weights;
    std::vector<float>().swap(temp);
    std::cout << "check\n";

    for(i = 0; i<n_iters; i++){
        g = lg_equation(x, weights);
        iden = eye(x.size());
        for(j = 0; j<g.size(); j++){
            g[j][0] -= y[j][0];
        }
        g = dot(inv(iden), g);
        equation = dot(x, transpose(weights));
        for(j = 0; j<equation.size(); j++){
            equation[j][0] += g[j][0];
        }

        inv_bracket = inv(dot(dot(transpose(x), iden), x));
        inv_bracket = dot(inv_bracket, transpose(x));
        weights = transpose(dot(dot(inv_bracket, iden), equation));
        if(!(present_nulls(weights))){
            back_up = weights;
        }else{
            weights = back_up;
            break;
        }
        for(j = 0; j<weights.size(); j++){
            for(k = 0; k<weights[0].size(); k++){
                std::cout << weights[j][k] << ' ';
            }
            std::cout << "\n";
        }
    }


    std::vector<std::vector<float>>().swap(g);
    std::vector<std::vector<float>>().swap(iden);
    std::vector<std::vector<float>>().swap(equation);
    std::vector<std::vector<float>>().swap(inv_bracket);

    for(i = 0; i<weights.size(); i++){
        for(j = 0; j<weights[0].size(); j++){
            std::cout << weights[i][j] << ' ';
        }
        std::cout << "\n";
    }
    return weights;
}


std::vector<std::vector<float>> lg_predict(std::vector<std::vector<float>> x, std::vector<std::vector<float>> weights){
    std::vector<std::vector<float>> res;
    res = lg_equation(x, weights);
    int i;
    for(i = 0; i<res.size(); i++){
        if(res[i][0] > 0.5){
            res[i][0] = (float)1;
        }else{
            res[i][0] = (float)0;
        }
    }

    return res;
}