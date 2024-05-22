#include "sort.h" 
bool seeded = false;

void fillRandom(int array[], int size, int max) {
    if (!seeded) {
        srand(time(nullptr));
        seeded = true;
    }
    for (int i = 0; i < size; i++)
        array[i] = rand() % max;
}

template<typename Ttype>
void bubbleSort(Ttype array[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size-i-1; j++) {
            if (array[j] > array[j+1]) {
                Ttype temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

template<typename Ttype> 
void quickSort(Ttype array[], int size) {
    if (size <= 1)
        return;

    Ttype lower[size], higher[size];
    int lowerSize = 0, higherSize = 0, equalSize = 0;

    Ttype pivot = array[0];
    for (int i = 0; i < size; i++) {
        if (array[i] < pivot)
            lower[lowerSize++] = array[i];
        else if (array[i] > pivot)
            higher[higherSize++] = array[i];
        else
            equalSize++;
    }
    quickSort(lower, lowerSize);
    quickSort(higher, higherSize);

    for (int i = 0; i < lowerSize; i++)
        array[i] = lower[i];
    for (int i = 0; i < equalSize; i++)
        array[i + lowerSize] = pivot;
    for (int i = 0; i < higherSize; i++)
        array[i + lowerSize + equalSize] = higher[i];
}

template<typename Ttype>
void mergeSort(Ttype array[], int size) {
    if (size <= 1)
        return;

    const int size1 = (int)size / 2;
    const int size2 = (int)size - size1;
    Ttype* array1 = array;
    Ttype* array2 = array + size1;
    mergeSort(array1, size1);
    mergeSort(array2, size2);

    int i1 = 0, i2 = 0;
    for (int i = 0; i < size; i++) {
        if (i2 == size2) {
            array[i] = array1[i1];
            i1++;
        } else if (i1 == size1) {
            array[i] = array2[i2];
            i2++;
        } else if (array1[i1] < array2[i2]) {
            array[i] = array1[i1];
            i1++;
        } else { // array1[i1] > array2[i2]
            array[i] = array2[i2];
            i2++;
        }
    }
}

// Explicit instantiations
template void bubbleSort<int>(int[], int);
template void bubbleSort<float>(float[], int);
template void bubbleSort<double>(double[], int);
template void bubbleSort<char>(char[], int);

template void quickSort<int>(int[], int);
template void quickSort<float>(float[], int);
template void quickSort<double>(double[], int);
template void quickSort<char>(char[], int);

template void mergeSort<int>(int[], int);
template void mergeSort<float>(float[], int);
template void mergeSort<double>(double[], int);
template void mergeSort<char>(char[], int);

