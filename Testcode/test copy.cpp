#include <string>
#include <iostream>
#include <sstream>
#include <bitset>
#include <fenv.h>

using namespace std;

int main()
{
    unsigned int imfuckingtired;
    stringstream ss;
    float n1f, n2f, res;
    n1f = n2f = res = 0.0;
    string n1;
    cin >> n1;
    n1f = stof(n1);
    int flag = 0;
#pragma region
    feclearexcept(FE_ALL_EXCEPT);

    flag = (fetestexcept(FE_DIVBYZERO)) ? 1 : 0;
    cout << "FE_DIVBYZERO = " << flag << endl;

    flag = (fetestexcept(FE_INEXACT)) ? 1 : 0;
    cout << "FE_INEXACT = " << flag << endl;

    flag = (fetestexcept(FE_INVALID)) ? 1 : 0;
    cout << "FE_INVALID = " << flag << endl;

    flag = (fetestexcept(FE_OVERFLOW)) ? 1 : 0;
    cout << "FE_OVERFLOW = " << flag << endl;

    flag = (fetestexcept(FE_UNDERFLOW)) ? 1 : 0;
    cout << "FE_UNDERFLOW = " << flag << endl;

    imfuckingtired = *(unsigned int *)&n1f;
    ss << bitset<1>((imfuckingtired >> 31)) << " " << bitset<8>((imfuckingtired >> 23)) << " " << bitset<23>(imfuckingtired) << n1f << endl;
#pragma endregion
    cout << ss.str();

    return 0;
}