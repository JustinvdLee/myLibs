#pragma once
#include <cstdint>

/* @brief Factorise a number into two primes
 * @param n the number to factorise
 * @param &p the address of the first  prime factor
 * @param &q the address of the second prime factor
 * @retval true if there were two prime factors, false if otherwise */
bool primeFactors(const uint64_t n, uint32_t &p, uint32_t &q);


/* @brief Calculate a random prime
 * @param max the maximum number that can be generated
 * @param rand a random generated number
 * @retval prime number below the max */
uint32_t generatePrime(const uint32_t max, const uint32_t rand);


/* @param Check is a number is prime 
 * @param p the number to check
 * @retval 0 if the number is a prime, else the lowest prime factor */
constexpr uint32_t prime(const uint64_t p);

