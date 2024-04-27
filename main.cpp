#include <iostream>
#include "primeLib.h"
#include "timingLib.h"

int main() {
    std::cout << "This is an library example to show how to include the correct files\n";
    std::cout << "If you want to use it, please have a look at the README.md!\n";

    Timing T;
    T.stop();

    uInt a, b;
    int i = 11 * 19;
    primeFactors(i, a, b);

    return 0;
}

