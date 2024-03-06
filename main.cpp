#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include "duo.hpp"

/*
- procurar o padrão ieee 754 
- fazer a conversão do decimal para binário, depois fazer a conversão para o padrão ieee 754
- precisa de:
    - valor lido
    - valor em float com erro
    - resposta lida com erro 
    - resposta correta
*/
using namespace std;



    string itob(int valor); //convert integer to binary
    string ftob(float valor); //convert fraction to binary
    duo stob(string valor); //convert string to binary
    string dtoi3e(duo d); // convert duo to ieee 754


// float ieee = 0(sinal) 00000000(expoente) 00000000000000000000000(mantissa)


int main()
{
#pragma region Variaveis

    string n1;
    char op = 0;  
    string n2;


#pragma endregion //variaveis

#pragma region Leitura

    cin >> n1;
    // cin >> op;
    // cin >> n2;

#pragma endregion //Leitura

#pragma region Conversao

#pragma endregion //Conversao
    
    // cout << n1 << "\n" << op << "\n" << n2 << endl;
    cout << stob(n1);
}




