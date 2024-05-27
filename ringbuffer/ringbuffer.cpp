#include "ringbuffer.h"

template<typename Ttype>
RingBuffer<Ttype>::RingBuffer(const uint16_t _size) : 
    buffer(new Ttype[_size]), writePtr(buffer), size(_size)
{
    reset();
}

template<typename Ttype>
Ttype RingBuffer<Ttype>::read(uint16_t index, bool &succes) const
{
    Ttype retval;
    memset(&retval, 0, sizeof(Ttype));

    succes = readTo(retval, index);
    return retval;
}

template<typename Ttype>
bool RingBuffer<Ttype>::readTo(Ttype &data, uint16_t index) const
{
    if (index > getSize()) { return false; }

    const auto copyPtr = writePtr - index;
    data = (copyPtr < buffer) ? *(copyPtr + size) : *copyPtr;
    return true;
}

template<typename Ttype>
void RingBuffer<Ttype>::write(Ttype data)
{
    if (++writePtr >= buffer + size) { writePtr = buffer; }
    *writePtr = data;
}

template<typename Ttype>
bool RingBuffer<Ttype>::write(Ttype data, uint16_t index)
{
    if (index > getSize()) { return false; }

    const auto copyPtr1 = writePtr + index;
    const auto copyPtr2 = (copyPtr1 > buffer + getSize()) ? (copyPtr1 - getSize()) : copyPtr1;
    *copyPtr2 = data;
    return true;
}

template<typename Ttype>
void RingBuffer<Ttype>::reset()
{
    memset(buffer, 0, sizeof(buffer) / sizeof(Ttype));
    writePtr = buffer;
}

template<typename Ttype>
RingBuffer<Ttype> RingBuffer<Ttype>::operator+(const RingBuffer<Ttype> &rhs)
{
    const uint16_t newSize = this->getSize() + rhs.getSize();
    RingBuffer<Ttype> newBuffer(newSize);

    bool succes = false;
    for (int i = 0; i < this->getSize(); i++)
        newBuffer.write(this->read(i, succes));
    for (int i = 0; i < rhs.getSize(); i++)
        newBuffer.write(rhs.read(i, succes));
    return newBuffer;
}

