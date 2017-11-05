#ifndef COMPUTATIONALMETHODS_UPPERRELAXATIONMETHOD_H
#define COMPUTATIONALMETHODS_UPPERRELAXATIONMETHOD_H

#include "../include/ComputionalMethods.h"

class UpperRelaxationMethod : public IComputionalMethod {
public:
    std::vector<double> compute(const Matrix &matrix, const std::vector<double> &b) override;
};

#endif //COMPUTATIONALMETHODS_UPPERRELAXATIONMETHOD_H
