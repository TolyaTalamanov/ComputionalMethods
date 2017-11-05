#include "../include/ComputionalMethods.h"
#include "GaussMethod.h"
#include "SeidelMethod.h"
#include "UpperRelaxationMethod.h"
#include "SimpleIterationMethod.h"
#include "KramerMethod.h"

std::unique_ptr<IComputionalMethod> IComputionalMethod::create(Implementation impl) {
    switch(impl){
        case Implementation::GAUSS :
            return std::unique_ptr<IComputionalMethod>(new GaussMethod());

        case Implementation::KRAMMER :
            return std::unique_ptr<IComputionalMethod>(new KramerMethod());

        case Implementation::SEIDEL :
            return std::unique_ptr<IComputionalMethod>(new SeidelMethod());

        case Implementation::SIMPLE_ITERATION :
            return std::unique_ptr<IComputionalMethod>(new SimpleIterationMethod());

        case Implementation::UPPER_RELAXATION :
            return std::unique_ptr<IComputionalMethod>(new UpperRelaxationMethod());

        default :
            return nullptr;

    }
}



