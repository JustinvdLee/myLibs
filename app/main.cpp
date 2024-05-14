#include <iostream>
#include "prime.h"
#include "timing.h"

int main() {
    std::cout << "This is an library example to show how to include the correct files\n";
    std::cout << "If you want to use it, please have a look at the README.md!\n";

    Timing T;
    T.stop();

    uint32_t a, b;
    uint16_t i = 11 * 19;
    primeFactors(i, a, b);

    return 0;
}

