#include <scratchy/BitWriter.hpp>

#define GET_MASK(x) (static_cast<uint64_t>(1) << x) - 1

void BitWriter::WriteBool(const bool input)
{
    WriteByte(static_cast<uint8_t>(input));
}

void BitWriter::WriteByte(const uint8_t input)
{

    int bits = 8 - __builtin_clz(input);

    uint64_t mask = GET_MASK(bits);

    scratch |= (input & mask) << scratch_bits;
    scratch_bits += bits;
    
    if(scratch_bits >= 32)
        Buffer();

}

void BitWriter::WriteInt(const uint32_t input)
{
    int bits = 32 - __builtin_clz(input);

    uint64_t mask = GET_MASK(bits);

    scratch |= (input & mask) << scratch_bits;
    scratch_bits += bits;
    
    if(scratch_bits >= 32)
        Buffer();
}


void BitWriter::WriteFloat(float input) 
{

     union FloatInt
    {
        float float_value;
        uint32_t int_value;
    };

    FloatInt tmp;

    tmp.float_value = input;

    WriteInt(tmp.int_value);
}

void BitWriter::Buffer() 
{
    buffer[word_index++] = __bswap_32(scratch & 0xFFFFFFFF);
    scratch >>= 32;
    scratch_bits -= 32;
}

void BitWriter::Flush() 
{
    buffer[word_index++] = __bswap_32(scratch & 0xFFFFFFFF);
    scratch >>= scratch_bits;
    scratch_bits = 0;
}