#include <string>
#include <sstream>
#include <iostream>
#include <bitset>
#include <fenv.h>

using namespace std;

unsigned flags[5] = {FE_DIVBYZERO, FE_INEXACT, FE_INVALID, FE_OVERFLOW, FE_UNDERFLOW};
string flagstr[5] = {"FE_DIVBYZERO", "FE_INEXACT", "FE_INVALID", "FE_OVERFLOW", "FE_UNDERFLOW"};

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

int main()
{
    float n1f, n2f, res;
    string n1, op, n2;
    cin >> n1 >> op >> n2;
    int flag;
    unsigned int imfuckingtired;
    stringstream ss;

    feclearexcept(FE_ALL_EXCEPT);
    n1f = stof(n1);
    n2f = stof(n2);

    switch (op[0])
    {
    case '+':
        res = n1f + n2f;
        break;
    case '-':
        res = n1f - n2f;
        break;
    case 'x':
        res = n1f * n2f;
        break;
    case '*':
        res = n1f * n2f;
        break;
    case 'X':
        res = n1f * n2f;
        break;
    case '/':
        res = n1f / n2f;
        break;
    default:
        cout << "Invalid operator";
        return 0;
    }

#pragma region BitConversion
    imfuckingtired = *(unsigned int *)&n1f;
    ss
        << bitset<1>((imfuckingtired >> 31))
        << " "
        << bitset<8>((imfuckingtired >> 23))
        << " "
        << bitset<23>(imfuckingtired)
        << "= "
        << n1f
        << endl;

    imfuckingtired = *(unsigned int *)&n2f;
    ss
        << bitset<1>((imfuckingtired >> 31))
        << " "
        << bitset<8>((imfuckingtired >> 23))
        << " "
        << bitset<23>(imfuckingtired)
        << "= "
        << n2f
        << endl;

    imfuckingtired = *(unsigned int *)&res;
    ss
        << bitset<1>((imfuckingtired >> 31))
        << " "
        << bitset<8>((imfuckingtired >> 23))
        << " "
        << bitset<23>(imfuckingtired)
        << "= "
        << res
        << endl;
#pragma endregion
    cout
        << ss.str()
        << endl
        << flags_str();

    return 0;
}