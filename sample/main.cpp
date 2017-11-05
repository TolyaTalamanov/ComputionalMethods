#include <iostream>
#include "../include/ComputionalMethods.h"

int main() {
    auto computionalMethod = IComputionalMethod::create(Implementation::GAUSS);
    Matrix m;
    std::vector<double> b;
    computionalMethod->compute(m, b);
    return 0;
}