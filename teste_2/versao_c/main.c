#include <stdio.h>
#include <stdlib.h>
#include "entradas.h"

int main(int argc, char const *argv[])
{
    float **chuva;
    int **chuva_status;
    int codigo;
    int *mes, *ano;
    size_t linhas;

    aloca_entradas(&mes, &ano, &chuva, &chuva_status);
    linhas = le_entrada("exemplo.txt", &codigo, mes, ano, chuva, chuva_status);
    print_entrada(linhas, codigo, mes, ano, chuva, chuva_status);

    free_entradas(linhas, &mes, &ano, &chuva, &chuva_status);

    return 0;
}

