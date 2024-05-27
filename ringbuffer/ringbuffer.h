/*
 *  lib: ringbuffer
 *      Have a ringbuffer with a write pointer
 *      The size is from 1 to 65535
 *      The write pointer points to the last written element
 *
 *  Properties:
 *      Date:   2024-05-22
 *      Status: Must haves completed
 *  
 *  Improvements:
 *      operator overloading (if logical)
 */
#pragma once
#include <cstdint>
#include <cstring>

/*! @brief ringbuffer of any type */
template<typename Ttype>
class RingBuffer {
public:
    /*! @brief constructor for ringbuffor of any type
     *  @param s the size of the buffer */
    explicit RingBuffer(const uint16_t);
    
    /*! @brief reads the last element that was written
     *  @return the value at the writePtr address */
    inline Ttype read() const { return *writePtr; }
    
    /*! @brief reads an element a specific number of writes ago
     *      returns zero in case of an error
     *  @param index how many elements ago
     *  @param succes written to true if the read succeeded
     *  @return the read value or zero */
    Ttype read(uint16_t, bool &) const;
    
    /*! @brief reads an element a specific number of writes ago
     *      writes nothing in case of an error
     *  @param data written to the read data 
     *  @param index how many elements ago
     *  @return true if the read succeeded, otherwise false */
    bool readTo(Ttype &, uint16_t) const;

    /*! @brief writes the next element into the buffer
     *  @param data the data to be written */
    void write(Ttype);

    /*! @brief overwrites a specific element of the buffer
     *  @param data the data to be written 
     *  @param index the place to be overwritten
     *  @return true if the write succeeded, otherwise false */
    bool write(Ttype, uint16_t);
    
    /*! @brief set all the memory for the array to zero */ 
    void reset();

    /*! @brief getter for the size
     *  @return the size of the buffer */
    uint8_t getSize() const { return size; }

    /* Operator overloads */

    RingBuffer<Ttype> operator+ (const RingBuffer<Ttype> &rhs);
    RingBuffer<Ttype> operator+=(const RingBuffer<Ttype> &rhs) { return (*this + rhs); }

private:
    const uint16_t size = 2;
    Ttype *buffer;
    Ttype *writePtr;
};

// Explicit instatiations
template class RingBuffer<int>;
template class RingBuffer<float>;
template class RingBuffer<double>;
template class RingBuffer<char>;

