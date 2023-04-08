#include "calcRoot.h"

int main() {
    calcRoot A;
    A.findRootDiv(2, 4, 0.001);
    std::cout << "method div root: " << A.getResult() << std::endl;
    std::cout << "method div count: " << A.getCountIteration() << std::endl;
    A.findRootNeuton(2, 4, 0.001);
    std::cout << "method neuton root: " << A.getResult() << std::endl;
    std::cout << "method neuton count: " << A.getCountIteration() << std::endl;
    A.findRootIter(2, 0.01);
    std::cout << "method simple iteration root: " << A.getResult() << std::endl;
    std::cout << "method simple iteration count: " << A.getCountIteration() << std::endl;
}