#include "primeLib.h" 

bool primeFactors(ulLong n, uInt &p, uInt &q) {
    uLong a = prime(n), b;

    if (a == 0)
        return false;

    b = n / a;
    if (prime(b) != 0)
        return false;

    if (a * b != n)
        return false;

    p = a;
    q = b;
    return true;
}

