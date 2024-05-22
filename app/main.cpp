#include <iostream>
#include "prime.h"
#include "ringbuffer.h"
#include "sort.h"
#include "timing.h"

using std::cout;
using std::endl;
constexpr int size = 5;

int main() {
    cout << "This is an example to show all and check the included libraries." << endl;
    cout << "If you want to use it, please have a look at the README.md!" << endl;

    uint32_t a, b;
    uint16_t i = 11 * 19;
    primeFactors(i, a, b);
    if (a != 11 || b != 19)
        cout << "Error in prime factors!" << endl;

    RingBuffer<int> buf(size);
    buf.write(1);
    buf.write(2);
    if (buf.read(1) != 1 || buf.read() != 2)
        cout << "Error reading buffer!" << endl;

    int array[size];
    fillRandom(array, size, 100);
    quickSort(array, size);
    for (int i = 1; i < size; i++) {
        if (array[i] < array[i-1])
            cout << "Error in sorted array!" << endl;
    }

    Timing T;
    T.stop();
    return 0;
}

