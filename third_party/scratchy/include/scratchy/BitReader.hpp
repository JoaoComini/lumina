#pragma once
#include <cstdint>
#include <iostream>

class BitReader {

public:

    BitReader();

    BitReader(const uint8_t *buffer, int size) : 
        buffer(reinterpret_cast<const uint32_t *>(buffer)), 
        buffer_size(size){
            
        total_bits = size*8;
    }

    bool ReadBool(int bits);
    uint8_t ReadByte(int bits);
    int32_t ReadInt(int bits);
    float ReadFloat(int bits);
    void Reset();

private:
    uint64_t scratch = 0x0;
    int scratch_bits = 0x0;
    int word_index = 0x0;
    const uint32_t *buffer;
    int total_bits;
    int num_bits_read = 0x0;
    int buffer_size;

    void Fill();    
};