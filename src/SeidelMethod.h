#ifndef COMPUTATIONALMETHODS_SEIDELMETHOD_H
#define COMPUTATIONALMETHODS_SEIDELMETHOD_H

#include "../include/ComputionalMethods.h"

class SeidelMethod : public IComputionalMethod {
public:
    std::vector<double> compute(const Matrix &matrix,
                                const std::vector<double> &b) override;

};

#endif //COMPUTATIONALMETHODS_SEIDELMETHOD_H
