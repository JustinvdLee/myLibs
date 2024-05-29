/*
 *  lib: sort
 *      differt sorting algorithms, to compare and learn
 *      input: array to Ttype, with a certain length
 *      The values get written correctly to the same place
 *
 *  Properties:
 *      Date:   2024-05-22
 *      Status: Must haves completed
 *  
 *  Improvements:
 *      Add more algorithms
 *      Add a function that can return a sorted copy and leave the origin intact
 *      Change the doxygen comments
 */
#pragma once
#include <cstdlib>
#include <ctime>

/* @brief fills an array with random values
 * @param array[] the pointer to the start of the array
 * @param size the size of the array
 * @param max the maximum number to be generated */
void fillRandom(int[], int, int);

/* @brief sorts an array using bubble sort
 * @param array[] the pointer to the start of the array
 * @param size the size of the array */
template<typename Ttype>
void bubbleSort(Ttype[], int);

/* @brief sorts an array using quick sort
 * @param array[] the pointer to the start of the array
 * @param size the size of the array */
template<typename Ttype> 
void quickSort(Ttype[], int);

/* @brief sorts an array using merge sort
 * @param array[] the pointer to the start of the array
 * @param size the size of the array */
template<typename Ttype>
void mergeSort(Ttype[], int);

