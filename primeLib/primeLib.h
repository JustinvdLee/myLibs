#pragma once

typedef unsigned long uLong;
typedef unsigned int  uInt ;
typedef unsigned long long ulLong;

/* Factorise a number into two primes
 * @param n: the number to factorise
 * &p the address of the first  prime factor
 * &q the address of the second prime factor
 * @retval true if there were two prime factors, false if otherwise */
bool primeFactors(ulLong n, uInt &p, uInt &q);

/* Check is a number is prime 
 * @param p: the number to check
 * @retval: 0 if the number is a prime, else the lowest prime factor */
constexpr uInt prime(const ulLong p) {
    if (p <= 1)     // 0, 1 and negative numbers are not prime (defined)
        return 1;
    if (p <= 3 || p == 5)     // 2 and 3 are primes
        return 0;
    if (p % 2 == 0) // all even numbers above 3 are not prime (obviously)
        return 2;
    if (p % 3 == 0) // all numbers devisible by 3 above 5 are not prime 
        return 3;

    // if we exceed the square root of the number and haven't found a divider, the number is prime 
    for (uInt i = 5; i*i <= p; i += 6) {
        if (p % i == 0)
            return i;
        if (p % (i+2) == 0)
            return i + 2;
    }
    return 0;
}

/* Generate a prime
 * @param max: the maximum number that can be generated
 * @retval: prime number below the max */
constexpr uInt generatePrime(const uLong max, const uLong rand) {
    if(max < 7)
        return 2;

    uInt number = rand % max;

    if (number % 2 == 0)
        number++;
    while (prime(number) != 0) 
        number -= 2;
    return number; 
}

