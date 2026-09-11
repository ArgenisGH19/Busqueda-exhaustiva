#include "BuscadorClaves.h"

BuscadorClaves::BuscadorClaves()
{
    //ctor
}

BuscadorClaves::~BuscadorClaves()
{
    //dtor
}

bool BuscadorClaves::validarClave(char *clave)
{
    if (clave == nullptr || clave[0] == '\0')
    {
        return false;
    }

    for (int i = 0; clave[i] != '\0'; i++)
    {
        char c = clave[i];

        if (!((c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')))
        {
            return false;
        }
    }

    return true;
}
}


