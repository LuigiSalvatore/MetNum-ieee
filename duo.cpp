#include "duo.hpp"

duo::duo()
    {
        this->binarioInt = "0";
        this->binarioFraction = "0";
    }
    
std::ostream& operator<<(std::ostream& os, const duo& d)
    {
        os << d.binarioInt << "." << d.binarioFraction;
        return os;
    }

duo stob(std::string valor) //convert std::string to binary
    {
        float num = stof(valor);
        int numi = (int)num;
        float numf = num - numi;
        duo binario;
        binario.binarioInt = itob(numi);
        binario.binarioFraction = ftob(numf);
        
        // return binarioInt + "." + binarioFloat;
        return binario;
        
    }
std::string ftob(float valor) //convert fraction to binary
{
    std::string binario = "";
    while (valor > 0)
    {
        valor = valor * 2;
        if (valor >= 1)
        {
            binario = binario + "1";
            valor = valor - 1;
        }
        else
        {
            binario = binario + "0";
        }
    }
    return binario;
}

std::string itob(int valor) //convert integer to binary
    {
        std::string binarioInt = "";
        while (valor > 0)
        {
            if (valor % 2 == 0)
                binarioInt = "0" + binarioInt;
            else
                binarioInt = "1" + binarioInt;
            valor = valor / 2;
        }
        return binarioInt;
    }
std::string dtoi3e(duo d) // convert duo to ieee 754
{
    std::string restante = d.binarioInt.replace(0, 1, "");
    std::string mantissa = restante + d.binarioFraction;
    int expoente = d.binarioInt.length() - 1 + 127;
}