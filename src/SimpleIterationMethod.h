#ifndef COMPUTATIONALMETHODS_SIMPLEITERATIONMETHOD_H
#define COMPUTATIONALMETHODS_SIMPLEITERATIONMETHOD_H

#include "../include/ComputionalMethods.h"

class SimpleIterationMethod : public IComputionalMethod {
public:
    std::vector<double> compute(const Matrix &matrix,
                                const std::vector<double> &b) override;

};


#endif //COMPUTATIONALMETHODS_SIMPLEITERATIONMETHOD_H
