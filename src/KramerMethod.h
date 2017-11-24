
#ifndef COMPUTATIONALMETHODS_KRAMERMETHOD_H
#define COMPUTATIONALMETHODS_KRAMERMETHOD_H

#include "../include/ComputionalMethods.h"

class KramerMethod : public IComputionalMethod {
public:
    std::vector<double> compute(const Matrix &matrix,
                                const std::vector<double> &b) override;

private:
   int getMaxRow(const Matrix& matrix, int col);
    double determinant(const Matrix &matrix);
    Matrix createSpecialMatrix(const Matrix &matrix, const std::vector<double> &b, int pos);
};

#endif //COMPUTATIONALMETHODS_KRAMERMETHOD_H
