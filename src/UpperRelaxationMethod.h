#ifndef COMPUTATIONALMETHODS_UPPERRELAXATIONMETHOD_H
#define COMPUTATIONALMETHODS_UPPERRELAXATIONMETHOD_H

#include "../include/ComputionalMethods.h"

class UpperRelaxationMethod : public IComputionalMethod {
public:
    std::vector<double> compute(const Matrix &matrix, const std::vector<double> &b, double omega) override;

private:
    void transpose(const Matrix &input, Matrix &output);
    Matrix multiplicationMatrix(const Matrix &matrix);
    std::vector<double> multiplicationMatVec(const Matrix &matrix,  const std::vector<double> &b);
};

#endif //COMPUTATIONALMETHODS_UPPERRELAXATIONMETHOD_H
