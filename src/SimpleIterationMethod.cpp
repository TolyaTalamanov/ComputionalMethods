#include "SimpleIterationMethod.h"
#include <iostream>
#include <cmath>
using namespace std;

const double epsilon = 0.1;

std::vector<double> SimpleIterationMethod::compute(const Matrix &matrix,
                                                   const std::vector<double> &b) {

    Matrix  A = matrix;
    vector<double> xNext(A.size());
    vector<double> B = b;
    int numMax = 0;
    int max[A.size()];
    int sum = 0;
    for(int i = 0; i < A.size(); i++) {
        max[i] = A[i][0];
        numMax = i + 0;
        for (int j = 1; j < A.size(); j++) {
            if (max[i] < A[i][j]){
                max[i] = A[i][j];
                numMax = i + j;
            }
        }
        sum += numMax;
    }
    if(sum != A.size() * (A.size() + 1)){
        std::cout << "Решение не сходится!" << std::endl;
        exit(-1);
    }
    else{
        for(int i = 0; i < A.size(); i++){
            iter_swap(A.begin() + i, A.begin() + max[i]);
            iter_swap(B.begin() + i, B.begin() + max[i]);
        }
        Matrix D(A.size());
        for(int i =0; i < A.size(); i++)
            for(int j = 0; j < A.size(); j++){
                if (i == j)
                    D[i][j] = 0;
                else{
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
            cout << "Решение не сходится!" << endl;
            exit(-1);
        }
        else{
            vector<double> xPrev(A.size());
            double  norma = 1;
            for(int i = 0; i < A.size(); i++)
            {
                xNext[i] = B[i];
            }
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
                    norma = xNext[i] - xPrev[i];
                }

            } while (norma >= epsilon);
        }

    }
    return xNext;
}
