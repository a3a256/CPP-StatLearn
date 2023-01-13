#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <vector>
// all functions are redefined all of a sudden, needs further search into the topic
std::vector<std::vector<int>> square(std::vector<std::vector<int>> vec){
    for(int i = 0; i<vec.size(); i++){
        for(int j = 0; j<vec[0].size(); j++){
            vec[i][j] = vec[i][j]*vec[i][j];
        }
    }
    return vec;
}

int argmax(std::vector<float> arr){
    int max=arr[0];
    int index=0;
    for(int i=0; i<arr.size(); i++){
        if(arr[i]>max){
            max = arr[i];
            index=i;
        }
    }
    return index;
}

int classes(int arr[], int size){
    static int u[50];
    u[0] = arr[0];
    int length = 1;
    bool exists=false;
    for(int i = 0; i<size; i++){
        exists=false;
        for(int j = 0; j<length; j++){
            if(u[j] == arr[i]){
                exists = true;
            }
        }
        if(!(exists)){
            u[length] = arr[i];
            length ++;
        }
    }
    return length;
}

std::vector<int> unique(std::vector<std::vector<int>> arr){
    std::vector<int> u;
    u.push_back(arr[0][0]);
    int length = 1;
    bool exists=false;
    for(int i = 0; i<arr.size(); i++){
        exists=false;
        for(int j = 0; j<length; j++){
            if(u[j] == arr[i][0]){
                exists = true;
            }
        }
        if(!(exists)){
            u.push_back(arr[i][0]);
            length ++;
        }
    }
    return u;
}

std::vector<int> bincount(std::vector<std::vector<int>> arr){
    std::vector<int> counts;
    int freq;
    std::vector<int> n_classes;
    n_classes = unique(arr);
    for(int i = 0; i<n_classes.size(); i++){
        freq = 0;
        for(int j = 0; j<arr.size(); j++){
            if(n_classes[i] == arr[j][0]){
                freq ++;
            }
        }
        counts.push_back(freq);
    }
    return counts;
}

std::vector<float> sorting(std::vector<float> arr){
    bool sorted = false;
    float temp=(float)0;
    while (!(sorted)){
        sorted = true;
        for(int i = 1; i<arr.size(); i++){
            if(arr[i]<arr[i-1]){
                sorted=false;
                temp = arr[i];
                arr[i] = arr[i-1];
                arr[i-1] = temp;
            }
        }
    }
    return arr;
}

std::vector<float> percentile(std::vector<float> arr, std::vector<int> percs){
    std::vector<float> modified;
    modified = sorting(arr);
    std::vector<int> ids;
    std::vector<float> percentages;
    for(int i = 0; i<percs.size(); i++){
        ids.push_back((arr.size()*percs[i])/100);
    }
    for(int i = 0; i<percs.size(); i++){
        percentages.push_back(modified[ids[i]]);
    }
    return percentages;
}

std::vector<float> quantiles(std::vector<float> arr){
    std::vector<float> quantile;
    std::vector<float> modified;
    modified = sorting(arr);
    int quarter = arr.size()/4;
    int three_quarter = quarter*3;
    quantile.push_back(modified[0]);
    quantile.push_back(modified[quarter]);
    quantile.push_back(modified[three_quarter]);
    quantile.push_back(modified[arr.size()-1]);
    return quantile;
}

std::vector<std::vector<float>> eye(std::vector<int> dim){
    std::vector<std::vector<float>> res;
    int rows, columns;
    if(dim.size() == 1){
        rows = dim.at(0);
        columns = dim.at(0);
    }else{
        rows = dim.at(0);
        columns = dim.at(1);
    }
    for(int i = 0; i<rows; i++){
        std::vector<float> temp;
        for(int j = 0; j<columns; j++){
            if(i == j){
                temp.push_back((float)1);
            }else{
                temp.push_back((float)0);
            }
        }
        res.push_back(temp);
    }
    return res;
}

float determinant(std::vector<std::vector<float>> arr){
    float det = 0.0f;
    if(arr.size() == 1){
        return arr[0][0];
    }
    std::vector<std::vector<float>> new_arr;
    std::vector<float> temp;
    for(int i = 0; i<arr[0].size(); i++){
        for(int j = 1; j<arr.size(); j++){
            for(int z  = 0; z<arr[0].size(); z++){
                if(z != i){
                    temp.push_back(arr[j][z]);
                }
            }
            new_arr.push_back(temp);
            std::vector<float>().swap(temp);
        }
        // std::cout << pow(-1, (1+i+1));
        det += pow(-1, (1+i+1))*arr[0][i]*determinant(new_arr);
        // std::cout << det << "\n";
        std::vector<std::vector<float>>().swap(new_arr);
    }
    return det;
}


std::vector<std::vector<float>> inv(std::vector<std::vector<float>> matrix){
    float det = 1/determinant(matrix);
    for(int i = 0; i<matrix.size(); i++){
        for(int j = 0; j < matrix[0].size(); j++){
            matrix[i][j] *= det;
        }
    }

    return matrix;
}



float** multiply_matrix(float arr1[][1000], float arr2[][1000], int rows1, int rows2, int cols1, int cols2){
    static float** new_arr = 0;
    new_arr = new float*[1000];
    for(int i = 0; i<rows1; i++){
        int a = 0;
        new_arr[i] = new float[1000];
        for(int j = 0; j<cols2; j++){
            for(int k=0; k<cols1; k++){
                a += arr1[i][k]*arr2[k][i];
            }
            new_arr[i][j] = a;
        }
    }
    return new_arr;
}

std::vector<std::vector<float>> dot(std::vector<std::vector<float>> arr1, std::vector<std::vector<float>> arr2){
    std::vector<std::vector<float>> res;
    float _sum;
    std::vector<float> temp;
    for(int i = 0; i < arr1.size(); i++){
        _sum=0;
        for(int j = 0; j<arr2[0].size(); j++){
            _sum = 0.0f;
            for(int k = 0; k<arr1[0].size(); k++){
                _sum += arr1[i][k]*arr2[k][i];
            }
            temp.push_back(_sum);
        }
        res.push_back(temp);
        std::vector<float>().swap(temp);
    }
    std::vector<std::vector<float>>().swap(arr1);
    std::vector<std::vector<float>>().swap(arr2);

    return res;
}


float** transpose_matrix(float arr[][1000], int rows, int columns){
    static float** new_arr = 0;
    new_arr = new float*[1000];
    for(int i = 0; i<columns; i++){
        new_arr[i] = new float[1000];
        for(int j =0; j<rows; j++){
            new_arr[i][j] = arr[j][i];
        }
    }

    return new_arr;
}

std::vector<std::vector<float>> transpose(std::vector<std::vector<float>> arr){
    std::vector<std::vector<float>> res;
    for(int i = 0; i<arr[0].size(); i++){
        std::vector<float> temp;
        for(int j = 0; j<arr.size(); j++){
            temp.push_back(arr[j][i]);
        }
        res.push_back(temp);
    }
    return res;
}


float* addition_1d(float arr[], float arr2[], int size){

    static float new_arr[1000];
    for(int i = 0; i<size; i++){
        new_arr[i] = arr[i] + arr2[i];
    }
    return new_arr;
}

float** transform_scaler(int arr[][1000], int rows, int columns){
    static float** new_arr = 0;
    static int min[1000];
    static int max[1000];
    for(int i = 0; i<columns; i++){
        min[i] = arr[0][i];
        max[i] = 1;
        for(int j = 0; j<rows; j++){
            if(min[i]>arr[j][i]){
                min[i] = arr[j][i];
            }
            if(max[i]<arr[j][i]){
                max[i] = arr[j][i];
            }
        }
    }
    new_arr = new float*[1000];
    for(int i =0; i<rows; i++){
        new_arr[i] = new float[1000];
        for(int j =0; j<columns; j++){
            new_arr[i][j] = 0;
        }
    }
    for(int i =0; i<columns; i++){
        for(int j =0; j<rows; j++){
            new_arr[j][i] = (arr[j][i]-min[i])/(max[i]-min[i]);
        }
    }
    return new_arr;
}

std::vector<float> mean_calculate(std::vector<std::vector<float>> arr, int axis){
    std::vector<float> res;
    float sum = 0.0f;
    if(arr.size() == 1){
        for(int i = 0; i<arr[0].size(); i++){
            sum += arr[0][i];
        }
        res.push_back(sum/(float)arr[0].size());
    }
    if(arr[0].size() == 1){
        for(int i = 0; i<arr.size(); i++){
            sum += arr[i][0];
        }
        res.push_back(sum/(float)arr.size());
        return res;
    }
    if(axis == 0){
        for(int i = 0; i<arr[0].size(); i++){
            for(int j = 0; j<arr.size(); j++){
                sum += arr[j][i];
            }
            res.push_back(sum/(float)arr.size());
            sum = 0.0f;
        }
    }else{
        for(int i = 0; i<arr.size(); i++){
            for(int j = 0; j<arr[0].size(); j++){
                sum += arr[i][j];
            }
            res.push_back(sum/(float)arr[0].size());
            sum = 0.0f;
        }
    }
    return res;
}

std::vector<float> standard_deviation(std::vector<std::vector<float>> arr){
    std::vector<float> r;
    std::vector<float> mn;
    mn = mean_calculate(arr, (int)0);
    float upper = 0.0f;
    float temp = 0.0f;
    if(arr[0].size() >= 2){
        for(int j = 0; j<arr[0].size(); j++){
            for(int i = 0; i<arr.size(); i++){
                temp = arr[i][j] - mn[j];
                upper += pow(temp, 2);
            }
            r.push_back(sqrt(upper/(float)arr.size()));
        }
    }
    return r;
}

float variance(std::vector<float> x){
    float res;
    std::vector<float> means;
    std::vector<std::vector<float>> temp;
    temp.push_back(x);
    means = mean_calculate(temp, (int)0);
    float val = 0.0f;

    for(int i = 0; i<x.size(); i++){
        val += pow(x[i]-means[0], 2);
    }

    res = val/(float)x.size();

    std::vector<float>().swap(means);
    std::vector<std::vector<float>>().swap(temp);

    return res;

}

float covariance(std::vector<float> x, std::vector<float> y){
    std::vector<float> means;
    std::vector<std::vector<float>> temp;
    temp.push_back(x);
    means.push_back(mean_calculate(temp, (int)0)[0]);
    std::vector<std::vector<float>>().swap(temp);
    temp.push_back(y);
    means.push_back(mean_calculate(temp, (int)0)[0]);
    std::vector<std::vector<float>>().swap(temp);
    float val = 0.0f;


    for(int i = 0; i<x.size(); i++){
        val += (x[i] - means[0])*(y[i] - means[1]);
    }


    return val/(float)x.size();
}


std::vector<std::vector<float>> cov(std::vector<std::vector<float>> arr){
    std::vector<std::vector<float>> res;
    std::vector<float> row;
    std::vector<float> temp;
    std::vector<float> x;
    std::vector<float> y;
    float val;
    for(int k = 0; k < arr[0].size(); k++){
        for(int i = 0; i < arr[0].size(); i++){
            for(int j = 0; j < arr.size(); j++){
                if(i == k){
                    x.push_back(arr[j][i]);
                }else{
                    x.push_back(arr[j][k]);
                    y.push_back(arr[j][i]);
                }
            }
            if(i == k){
                temp.push_back(variance(x));
            }else{
                temp.push_back(covariance(x, y));
            }
            std::vector<float>().swap(x);
            std::vector<float>().swap(y);
        }
        res.push_back(temp);
        std::vector<float>().swap(temp);
    }


    return res;
}

std::vector<float> sort(std::vector<float> left, std::vector<float> right, float pivot){
    left.push_back(pivot);
    if(right.size() == 0){
        return left;
    }
    for(int i = 0; i<right.size(); i++){
        left.push_back(right[i]);
    }
    return left;
}


std::vector<float> quickSort(std::vector<float> arr){
    if(arr.size() <= 1){
        return arr;
    }
    int length = arr.size();
    float pivot = arr.at((float)length-1);
    std::vector<float> right;
    std::vector<float> left;
    for(int i = 0; i<length-1; i++){
        if(arr[i] > pivot){
            right.push_back(arr[i]);
        }else{
            left.push_back(arr[i]);
        }
    }
    return sort(quickSort(left), quickSort(right), pivot);
}
