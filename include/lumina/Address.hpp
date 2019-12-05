#pragma once

class Address {
public:

    Address(){}

    Address(unsigned char a, 
                unsigned char b, 
                unsigned char c, 
                unsigned char d, 
                unsigned short port );

    Address(unsigned int address, unsigned short port);

    unsigned int GetAddress() const;
    void SetAddress(unsigned char a, unsigned char b, unsigned char c, unsigned char d);
    void SetAddress(unsigned int address);

    unsigned short GetPort() const;
    void SetPort(unsigned short port);

private:

    unsigned int address;
    unsigned short port;
};