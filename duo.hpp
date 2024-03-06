#ifndef DUO_HPP
#define DUO_HPP

#include <iostream>
#include <string>

class duo 
{
    public:
    std::string binarioInt;
    std::string binarioFraction;
    std::string sinal;
    duo();
    friend std::ostream& operator<<(std::ostream& os, const duo& d);
};
duo stob(std::string valor); //convert string to binary
std::string ftob(float valor); //convert fraction to binary
std::string itob(int valor); //convert integer to binary
std::string dtoi3e(duo d); // convert duo to ieee 754

#endif