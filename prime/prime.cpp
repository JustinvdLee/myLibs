#include "prime.h" 

bool primeFactors(uint64_t n, uint32_t &p, uint32_t &q)
{
    uint32_t a = prime(n);
    if (a == 0)         return false;

    uint32_t b = n / a;
    if (prime(b) != 0)  return false;
    if (a * b != n)     return false;

    p = a;
    q = b;
    return true;
}

uint32_t generatePrime(const uint32_t max, const uint32_t rand)
{
    if(max < 7) return 2;

    uint32_t number = rand % max;

    if (number % 2 == 0)
        number++;
    while (prime(number) != 0) 
        number -= 2;
    return number; 
}

constexpr uint32_t prime(const uint64_t p)
{
    if (p <= 1) return 1;       // 0, 1 and negative numbers are not prime (defined)
    if (p <= 3 || p == 5)
        return 0;               // 2 and 3 and 5 are primes
    if (p % 2 == 0) return 2;   // all even numbers above 3 are not prime (obviously)
    if (p % 3 == 0) return 3;   // all numbers above 5 devisible by 3 are not prime 

    // if we exceed the square root of the number and haven't found a divider, the number is prime 
    for (uint32_t i = 5; i*i <= p; i += 6) {
        if (p % i     == 0) return i;
        if (p % (i+2) == 0) return i+2;
    }
    return 0;
}

