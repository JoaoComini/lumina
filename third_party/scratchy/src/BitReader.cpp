#include <scratchy/BitReader.hpp>

#define GET_MASK(x) (static_cast<uint64_t>(1) << x) - 1

bool BitReader::ReadBool(int bits)
{

    uint64_t mask = GET_MASK(bits);

    if(bits > scratch_bits)
        Fill();
    
    int value = scratch & mask;
    
    scratch >>= bits;
    scratch_bits -= bits;

    return value;
}

uint8_t BitReader::ReadByte(int bits)
{

    uint64_t mask = GET_MASK(bits);

     if(bits > scratch_bits)
        Fill();

    uint8_t value = scratch & mask;

    scratch >>= bits;
    scratch_bits -= bits;

    return value;
}

int32_t BitReader::ReadInt(int bits)
{

    uint64_t mask = GET_MASK(bits);

    if(bits > scratch_bits)
        Fill();

    int32_t value = scratch & mask;

    scratch >>= bits;
    scratch_bits -= bits;

    return value;

}

float BitReader::ReadFloat(int bits)
{

    union FloatInt
    {
        float float_value;
        uint32_t int_value;
    };

    FloatInt tmp;

    tmp.int_value = (uint32_t) ReadInt(bits);

    return tmp.float_value;
}

void BitReader::Fill()
{
    scratch |= static_cast<uint64_t>(__bswap_32(buffer[word_index++])) << scratch_bits;

    scratch_bits += 32;
}
