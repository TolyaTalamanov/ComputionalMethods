#ifndef COMPUTATIONALMETHODS_COMPUTIONALMETHODS_H
#define COMPUTATIONALMETHODS_COMPUTIONALMETHODS_H
#define EXPORT __attribute__((visibility ("default")))

#include <vector>
#include <memory>

enum class Implementation{
    GAUSS,
    KRAMMER,
    SEIDEL,
    SIMPLE_ITERATION,
    UPPER_RELAXATION
};

using Matrix = std::vector<std::vector<double>>;
class EXPORT IComputionalMethod{
public:
    virtual std::vector<double> compute(const Matrix& matrix,
                                        const std::vector<double>& b) = 0;

    static std::unique_ptr<IComputionalMethod> create(Implementation impl);

};

#endif //COMPUTATIONALMETHODS_COMPUTIONALMETHODS_H

