#include <iostream>
#include <iterator>
#include "../include/ComputionalMethods.h"
using  namespace std;

int main() {

    auto computionalMethod = IComputionalMethod::create(Implementation::GAUSS);
    Matrix m = {{1, -1, 1, -1}, {1, 1.5, 2, 4}, {2, 3, 6.5, 10}, {2, -4, 1, -6}};
    std::vector<double> b{4, 8, 20, 4};
    std::vector<double>x(4);


    x = computionalMethod->compute(m, b);
    std::copy(x.begin(), x.end(), std::ostream_iterator<double>(std::cout, "\n"));
    return 0;
}

