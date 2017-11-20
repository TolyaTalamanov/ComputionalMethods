#include "SimpleIterationMethod.h"
#include <iostream>
#include <cmath>
using namespace std;

const double epsilon = 0.1;

std::vector<double> SimpleIterationMethod::compute(const Matrix &matrix,
                                                   const std::vector<double> &b) {

    vector<double> xNext(matrix.size());
    vector<double> B = b;
    int numMax = 0;
    int max[matrix.size()];
    int sum = 0;
    for(int i = 0; i <matrix.size(); i++) {
        max[i] =matrix[i][0];
        numMax = i + 0;
        for (int j = 1; j < matrix.size(); j++) {
            if (max[i] < matrix[i][j]){
                max[i] = matrix[i][j];
                numMax = i + j;
            }
        }
        sum += numMax;
    }
    if(sum != matrix.size() * (matrix.size() - 1)){
        std::cout << "Решение не сходится!" << std::endl;
        exit(-1);
    }
    Matrix  A = matrix;
    for(int i = 0; i < A.size(); i++) {
            A[i] = matrix[max[A.size() - i]];
    }
    Matrix D(matrix.size());
    for(int i =0; i < A.size(); i++)
        for(int j = 0; j < A.size(); j++){
            if (i == j)
                D[i][j] = 0;
            else {
                D[i][j] = (-1) * A[i][j] / A[i][i];
                B[i] /= D[i][i];
            }
        }
    double sumRow;
    double  maxSum = 0;
    for(int i =0; i < A.size(); i++) {
        sumRow = 0;
        for (int j = 0; j < A.size(); j++) {
            sumRow += abs(D[i][j]);
        }
        if (sumRow > maxSum)
            maxSum = sumRow;
    }
    if (maxSum >= 1){
        cout << "Решение не сходится!!" << endl;
        exit(-1);
    }

    vector<double> xPrev(A.size());
    double  norma = 1;
    for(int i = 0; i < A.size(); i++)
        xNext[i] = B[i];
    do{
        for (int i = 0; i < A.size();i++ ){
            xPrev[i] = xNext[i];
            xNext[i] = 0;
        }
        for (int i =0; i < A.size(); i++){
            for(int j = 0; j < A.size(); j++){
                xNext[i] += D[i][j] * xPrev[j];
            }
            xNext[i] +=B[i];
            if (norma < xNext[i] - xPrev[i])
                norma = xNext[i] - xPrev[i];
        }
    } while (norma >= epsilon);

    return xNext;
}