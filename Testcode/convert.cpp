
#include <string>

using namespace std;
#define BIAS 127
#define MAX 32

struct ieee754
{
    string sinal;
    string expoente;
    string mantissa;
    float valor;
};

struct duo
{
    string binarioInt;
    string binarioFraction;
};

string conv(float val)
{
    if (val == 0)
        return "0 00000000 00000000000000000000000";
    // if val infinite or nan
    char a[32];
    ieee754 ieee;
    ieee.sinal = val < 0 ? "1 " : " 0 "; // set sinal
    ieee.valor = val;
    val = val < 0 ? -val : val; // make val positive

    int num = (int)val;     // get integer part
    float numf = val - num; // get fraction part
    itoa(num, a, 2);        // convert integer part to binary

    ieee.expoente = "00000000";
    ieee.mantissa = "00000000000000000000000";
    return ieee.sinal + " " + ieee.expoente + " " + ieee.mantissa;
}