#include<iostream>
#include "KramerMethod.h"

std::vector<double> KramerMethod::compute(const Matrix &matrix,
                                          const std::vector<double> &b) {
    std::vector<double> result(b.size());
    std::vector<double> coefdet(b.size());
    double det = determinant(matrix);
    if (det == 0){
        std::cout << "Определитель матрицы равен нулю!" << std::endl;
        exit(-1);
    }
    for (int i = 0; i < matrix[0].size(); i++) {
        coefdet[i] = determinant(createSpecialMatrix(matrix, b, i));  //побочные миноры
        result[i] = coefdet[i] / det;
    }
    return result;
}
int KramerMethod::getMaxRow(const Matrix& matrix, int col) {
    double max = matrix[col][col];
    int imax = col;
    for(int i = col + 1; i < matrix.size(); i++){
        if(abs(matrix[i][col]) > max){
            max = abs(matrix[i][col]);
            imax = i;
        }
    }
    return imax;
}


double KramerMethod::determinant(const Matrix &matrix) {
    Matrix A = matrix;
    double result = 0;
    double d = 0;
    std::vector<double> vect = A[0];
    for (int k = 0; k < vect.size(); k++) { // ïðÿìîé õîä
        for (int j = k + 1; j < vect.size(); j++) {
            if (A[k][k] == 0){
                return result;
            }
            d = A[j][k] / A[k][k]; // ôîðìóëà (1)
            for (int i = k; i < A.size(); i++) {
                A[j][i] = A[j][i] - d * A[k][i]; // ôîðìóëà (2)
            }
        }
    }
    result = 1;
    for (int i = 0; i < A.size(); i++) {
        result *= A[i][i];
    }
    return result;
}
//    Matrix A = matrix;
//    int swapRow;
//    int size = A.size();
//    double coeff;
//    for(int i = 0; i < size - 1; i++) {
//        swapRow = getMaxRow(A, i);
//        std::iter_swap(A.begin() + swapRow, A.begin() + i);
//        for(int k  = i; k < size - 1; k++ ){
//            coeff = A[k + 1][i] / A[i][i];
//            for(int j = 0; j < size; j++){
//                A[k + 1][j] -= A[i][j] * coeff;
//            }
//        }
//    }
//    // до этого был Гаусс прямой проход
//    double  det = 1;
//    for(int i = 0; i < size; i++) {
//        det *= A[i][i];
//    }
//    return det;
//}

Matrix KramerMethod::createSpecialMatrix(const Matrix &matrix, const std::vector<double> &b, int pos) {
    Matrix A = matrix;
    for (int i = 0; i < b.size(); i++) {
        A[i][pos] = b[i];
    }
    return A;
}
