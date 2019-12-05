#include <lumina/Address.hpp>

Address::Address(unsigned char a, unsigned char b, unsigned char c, unsigned char d, unsigned short port) {

    Address::SetAddress(a, b, c, d);

    this->port = port;
}

Address::Address(unsigned int address, unsigned short port){
    this->address = address;
    this->port = port;
}

unsigned int Address::GetAddress() const {
    return this->address;
}

void Address::SetAddress(unsigned char a, unsigned char b, unsigned char c, unsigned char d){
    this->address = ( a << 24 ) | ( b << 16 ) | ( c << 8  ) | d;
}

void Address::SetAddress(unsigned int address) {
    this->address = address;
}

unsigned short Address::GetPort() const {
    return this->port;
}

void Address::SetPort(unsigned short port) {
    this->port = port;
}