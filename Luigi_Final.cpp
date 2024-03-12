#include <string>
#include <sstream>
#include <iostream>
#include <bitset>
#include <fenv.h>

using namespace std;

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

#pragma region Flags

    flag = (fetestexcept(FE_DIVBYZERO)) ? 1 : 0;
    ss
        << "FE_DIVBYZERO = "
        << flag
        << endl;

    flag = (fetestexcept(FE_INEXACT)) ? 1 : 0;
    ss
        << "FE_INEXACT = "
        << flag
        << endl;

    flag = (fetestexcept(FE_INVALID)) ? 1 : 0;
    ss
        << "FE_INVALID = "
        << flag
        << endl;

    flag = (fetestexcept(FE_OVERFLOW)) ? 1 : 0;
    ss
        << "FE_OVERFLOW = "
        << flag
        << endl;

    flag = (fetestexcept(FE_UNDERFLOW)) ? 1 : 0;
    ss
        << "FE_UNDERFLOW = "
        << flag
        << endl;
#pragma endregion

    cout << ss.str();

    return 0;
}