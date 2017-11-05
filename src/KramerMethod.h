
#ifndef COMPUTATIONALMETHODS_KRAMERMETHOD_H
#define COMPUTATIONALMETHODS_KRAMERMETHOD_H

#include "../include/ComputionalMethods.h"

class KramerMethod : public IComputionalMethod {
public:
    std::vector<double> compute(const Matrix &matrix,
                                const std::vector<double> &b) override;

};

#endif //COMPUTATIONALMETHODS_KRAMERMETHOD_H
