#include "../include/ComputionalMethods.h"
#ifndef COMPUTATIONALMETHODS_GAUSSMETHOD_H
#define COMPUTATIONALMETHODS_GAUSSMETHOD_H

class GaussMethod : public IComputionalMethod {
public:
    std::vector<double> compute(const Matrix& matrix,
                                const std::vector<double>& b) override;
};

#endif //COMPUTATIONALMETHODS_GAUSSMETHOD_H
