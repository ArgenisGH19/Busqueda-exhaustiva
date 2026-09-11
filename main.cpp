#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
#include <BuscadorClaves.h>

#define C 3

using namespace std;

int main()
{
    char clave [C + 1];
    BuscadorClaves bc;
    printf("Ingrese una clave en mayusculas A-Z y numeros del 0-9 de %d caracteres", C);
    scanf("%s", clave);

    if (bc.validarClave(clave) == false){
        printf("Clave no valida, intenta nuevamente\n");
    }
    return 0;
}
