#pragma once
#include <cstdint>
#include <iostream>

class BitWriter {

    public:

        BitWriter(uint8_t *buffer, int size) : buffer(reinterpret_cast<uint32_t*>(buffer)), buffer_size(size){}

        void WriteBool(const bool input);

        void WriteByte(const uint8_t input);

        void WriteInt(const uint32_t input);

        void WriteFloat(const float input);

        void Flush();
    
    private:
        uint64_t scratch = 0x0;
        int scratch_bits = 0x0;
        int word_index = 0x0;
        uint32_t *buffer;
        int buffer_size;

        void Buffer();

};