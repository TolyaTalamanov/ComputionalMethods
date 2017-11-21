#include "SimpleIterationMethod.h"
#include <iostream>
#include <cmath>
#include <numeric>
#include <algorithm>

using namespace std;

const double epsilon = 0.01;

std::vector<double> SimpleIterationMethod::compute(const Matrix &matrix,
                                                   const std::vector<double> &b) {
//  int numMax = 0;
    vector<int> max_pos(matrix.size());
    int sum = 0;
    for(int i = 0; i < matrix.size(); i++) {
        auto max_it = std::max_element(matrix[i].begin(), matrix[i].end(), [](int a, int b){
            return (std::abs(a) < std::abs(b));
        });
        max_pos[i] = std::distance(matrix[i].begin(), max_it);
        if (*max_it == 0) {
            if (b[*max_it] == 0)
                cout << "Система имеет бесконечно много решений" << endl;
            else
                cout << "Система не имеет решений" << endl;
            exit(-1);
        }
    }
    sum = accumulate(max_pos.begin(), max_pos.end(), 0);

    if(sum != matrix.size() * (matrix.size() - 1) / 2){
        std::cout << "Решение не сходится!" << std::endl;
        exit(-1);
    }
    Matrix  A = matrix;
    vector<double> B = b;
    for(int i = 0; i < matrix.size(); i++) {
        copy(matrix[i].begin(), matrix[i].end(), A[max_pos[i]].begin());
        B[max_pos[i]] = b[i];
    }

    Matrix D(matrix.size());
    for(int i = 0; i < D.size(); i++) {
        D[i].resize(D.size());
        for (int j = 0; j < D.size(); j++) {
            if (i == j)
                 D[i][j] = 0;
            else {
               D[i][j] = (-1) * A[i][j] / A[i][i];
            }
        }
        B[i] /= A[i][i]; //проверь какая матрица должна быть
    }
    for(int i = 0; i < D.size(); i++) {
        for (int j = 0; j < D.size(); j++)
            cout << D[i][j] << " ";
        cout << endl;
    }
    for(int i = 0; i < matrix.size(); i++) {
        cout << B[i] << " ";
    }
    cout << endl;
    double sumRow ;
    double  maxSum = 0;
    for(int i = 0; i < D.size(); i++) {
//        sumRow = std::accumulate(D[i].begin(), D[i].end(), 0.0, [](double& sum, double& val){
//            cout << "sum = " << sum << endl;
//            cout << "val = " << val  << endl;
//            sum += std::abs(val);
//            return sum;
//        });
        sumRow = 0;
        for (int j = 0; j < D.size(); j++) {
            sumRow += std::abs(D[i][j]);
        }
       // cout << "sumrow = " << sumRow << endl;
        if (sumRow > maxSum)
            maxSum = sumRow;
    }
   // cout << "maxSum = " << maxSum << endl;
    if (maxSum >= 1){
        cout << "Решение не сходится!!" << endl;
        exit(-1);
    }
    vector<double> xNext(matrix.size());
    vector<double> xPrev(A.size());
    double  norma = epsilon;
    copy(B.begin(), B.end(), xNext.begin());
    int iteration = 0;
    do{
        copy(xNext.begin(), xNext.end(), xPrev.begin());
        fill(xNext.begin(), xNext.end(), 0.0);

        for (int i = 0; i < A.size(); i++){
            for(int j = 0; j < A.size(); j++){
                xNext[i] += D[i][j] * xPrev[j];
            }
            xNext[i] += B[i];
            if (norma < fabs(xNext[i] - xPrev[i]))
                norma = fabs(xNext[i] - xPrev[i]);
        }
        iteration++;
    } while (norma >= epsilon && iteration < 1000);

    return xNext;
}