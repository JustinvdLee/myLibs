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
 *      Improving error handling for incorrect input.
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
    RingBuffer(uint16_t);

    /*! @brief destructor to free the memory */
    ~RingBuffer() { delete[] buffer; }
    
    /*! @brief reads the last element that was written
     *  @return the value at the writePtr address */
    inline Ttype read() const { return *writePtr; }
    
    /*! @brief reads an element a specific number of writes ago
     *  @param index how many elements ago (< size)
     *  @return the value that was read at that place */
    Ttype read(uint16_t) const;

    /*! @brief writes the next element into the buffer
     *  @param data the data to be written */
    void write(Ttype);

    /*! @brief overwrites a specific element of the buffer
     *  @param data the data to be written 
     *  @param index the place to be overwritten */
    //void write(Ttype, uint8_t);
    
    /*! @brief set all the memory for the array to zero */ 
    void reset();

    /*! @brief getter for the size
     *  @return the size of the buffer */
    uint8_t getSize() const { return size; }

private:
    const uint16_t size;
    Ttype *buffer;
    Ttype *writePtr;
};

// Explicit instatiations
template class RingBuffer<int>;
template class RingBuffer<float>;
template class RingBuffer<double>;
template class RingBuffer<char>;

