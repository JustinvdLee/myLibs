#include "ringbuffer.h"

template<typename Ttype>
RingBuffer<Ttype>::RingBuffer(uint16_t s) : 
    buffer(new Ttype[s]), writePtr(buffer), size(s)
{
    reset();
}

template<typename Ttype>
Ttype RingBuffer<Ttype>::read(uint16_t index) const
{
    if (index > size) { return read(); }

    const auto copyPtr = writePtr - index;
    return (copyPtr < buffer) ? *(copyPtr + size) : *copyPtr;
}

template<typename Ttype>
void RingBuffer<Ttype>::write(Ttype data)
{
    if (++writePtr >= buffer + size) { writePtr = buffer; }
    *writePtr = data;
}

/*
template<typename Ttype>
void RingBuffer<Ttype>::write(Ttype, uint8_t)
{
}
*/

template<typename Ttype>
void RingBuffer<Ttype>::reset()
{
    memset(buffer, 0, sizeof(buffer) / sizeof(Ttype));
    writePtr = buffer;
}

