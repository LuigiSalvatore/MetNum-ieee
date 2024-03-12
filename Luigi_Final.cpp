#include <string>
#include <sstream>
#include <iostream>
#include <bitset>
#include <fenv.h>

using namespace std;

string bitConversion(const float f);
string flags_str();

const unsigned flags[5] = {FE_DIVBYZERO, FE_INEXACT, FE_INVALID, FE_OVERFLOW, FE_UNDERFLOW};
const string flagstr[5] = {"FE_DIVBYZERO", "FE_INEXACT", "FE_INVALID", "FE_OVERFLOW", "FE_UNDERFLOW"};

int main()
{
    float f[3] = {0, 0, 0};
    string s[2], op;
    cin >> s[0] >> op >> s[1];
    stringstream ss;

    for (int i = 0; i < 2; i++)
        f[i] = stof(s[i]);

    feclearexcept(FE_ALL_EXCEPT);

    switch (op[0])
    {
    case '+':
        f[2] = f[0] + f[1];
        break;
    case '-':
        f[2] = f[0] - f[1];
        break;
    case 'x':
        f[2] = f[0] * f[1];
        break;
    case '*':
        f[2] = f[0] * f[1];
        break;
    case 'X':
        f[2] = f[0] * f[1];
        break;
    case '/':
        f[2] = f[0] / f[1];
        break;
    default:
        cout << "Invalid operator";
        return 0;
    }
    for (int i = 0; i < 3; i++)
        ss << bitConversion(f[i]);
    cout
        << ss.str()
        << endl
        << flags_str();

    return 0;
}

string bitConversion(const float f)
{
    stringstream ss;
    unsigned int UI = *(unsigned int *)&f;
    ss
        << bitset<1>((UI >> 31))
        << " "
        << bitset<8>((UI >> 23))
        << " "
        << bitset<23>(UI)
        << "= "
        << f
        << endl;
    return ss.str();
}

string flags_str()
{
    stringstream ss;
    int flag = 0;
    for (int i = 0; i < 5; i++)
    {
        flag = (fetestexcept(flags[i])) ? 1 : 0;
        ss << flagstr[i] << " = " << flag << endl;
    }
    return ss.str();
}
