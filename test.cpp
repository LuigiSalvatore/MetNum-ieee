#include <math.h>
#include <string>
#include <iostream>

using namespace std;
struct flags
{
    bool good;
    bool FE_DIVBYZERO;
    bool FE_INEXACT;
    bool FE_INVALID;
    bool FE_OVERFLOW;
    bool FE_UNDERFLOW;
};

string checkError(float val)
{
    string str = "INVALID";
    
    switch (fpclassify(val)) 
    {
    case FP_INFINITE:  
        str = "infinite";
            break;
    case FP_NAN:       
        str = "NaN";
            break;
    case FP_ZERO:      
        str = "zero";
            break;
    case FP_SUBNORMAL: 
        str = "subnormal";
            break;
    case FP_NORMAL:    
        str = "normal";
            break;
  }
    return str;
}

int main()
{ 
    float n1f = 0.0;
    float n2f = 0.0;
    float res = 0.0;
    string n1;
    string op;
    string n2;

    cin >> n1;
    cin >> op;
    cin >> n2;

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
            if (n2f == 0)
            {
            
            }
            res = n1f / n2f;
            break;
        default:
            cout << "Invalid operator";
            break;
    }
    cout << "float: " << n1f << endl;
    cout << "float: " << n2f << endl;
    cout << "result; " << res << endl;
    if (n2f == 0 && op[0] == '/')
    cout << "the operation is "<< checkError(res) << endl;

    main();

    return 0;
}