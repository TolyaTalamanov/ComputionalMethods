#ifndef COMPUTATIONALMETHODS_SEIDELMETHOD_H
#define COMPUTATIONALMETHODS_SEIDELMETHOD_H

#include "../include/ComputionalMethods.h"

class SeidelMethod : public IComputionalMethod {
public:
    std::vector<double> compute(const Matrix &matrix,
                                const std::vector<double> &b) override;

private:
    void transpose(const Matrix &input, Matrix &output);
    Matrix multiplicationMatrix(const Matrix &matrix);
    std::vector<double> multiplicationMatVec(const Matrix &matrix,  const std::vector<double> &b);
};

#endif //COMPUTATIONALMETHODS_SEIDELMETHOD_H
