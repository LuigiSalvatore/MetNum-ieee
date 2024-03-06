#include <stdlib.h>
#include <stdio.h>
#include "duo.hpp"

using namespace std;

struct ieee {
    string sinal;
    string expoente;
    string mantissa;
    string bias;
    string valorDecimal;
};
int main()
{ 
    string n1;
    duo d;
    cin >> n1;
    
    d = stob(n1); // retorna um duo; (binarioInt, binarioFraction)
    // convert to ieee 754

    return 0;
}