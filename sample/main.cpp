#include <iostream>
#include <iterator>
#include "../include/ComputionalMethods.h"
using  namespace std;

int main() {
    auto computionalMethod = IComputionalMethod::create(Implementation::SIMPLE_ITERATION);
    Matrix m = {{2, 2, 10}, {10, 1, 1}, {2, 10, 1}};
    std::vector<double> b{14, 12, 13};
    std::vector<double>x(3);

    x = computionalMethod->compute(m, b);
    std::copy(x.begin(), x.end(), std::ostream_iterator<double>(std::cout, "\n"));
    return 0;
}