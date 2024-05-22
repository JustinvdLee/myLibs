#include <iostream>
#include "prime.h"
#include "timing.h"
#include "ringbuffer.h"

using std::cout;
using std::endl;

int main() {
    cout << "This is an example to show all the included libraries." << endl;
    cout << "If you want to use it, please have a look at the README.md!" << endl;

    Timing T;
    T.stop();

    uint32_t a, b;
    uint16_t i = 11 * 19;
    primeFactors(i, a, b);

    RingBuffer<int> buf(3);
    buf.write(1);
    buf.write(2);
    if (buf.read(1) != 1 || buf.read() != 2)
        cout << "Error reading buffer!" << endl;

    return 0;
}

