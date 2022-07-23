#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "entradas.h"

void aloca_entradas(int **mes, int **ano, float ***chuva, int ***chuva_status)
{
    (*mes) = (int *)malloc(sizeof(int) * MAX_LINES);
    (*ano) = (int *)malloc(sizeof(int) * MAX_LINES);
    (*chuva) = (float **)malloc(sizeof(float *) * MAX_LINES);
    (*chuva_status) = (int **)malloc(sizeof(int *) * MAX_LINES);
    for (size_t i = 0; i < MAX_LINES; i++)
    {
        (*chuva)[i] = (float *)malloc(sizeof(float) * 31);
        (*chuva_status)[i] = (int *)malloc(sizeof(int) * 31);
    }
}

void free_entradas(size_t linhas, int **mes, int **ano, float ***chuva, int ***chuva_status)
{
    free(*mes);
    free(*ano);
    for (size_t i = 0; i < (size_t)linhas; i++)
    {
        free((*chuva)[i]);
        free((*chuva_status)[i]);
    }
    free(*chuva);
    free(*chuva_status);
}

int le_entrada(const char *arq_entrada, int *codigo, int *mes, int *ano, float **chuva, int **chuva_status)
{
    FILE *f_in;
    char buf[1024];
    int linhas = 0;

    setlocale(LC_NUMERIC, "pt_BR.UTF-8");

    f_in = fopen(arq_entrada, "r");
    for (size_t i = 0; i < 13; i++)
    {
        fgets(buf, sizeof(buf), f_in);
    }

    for (size_t i = 0; i < MAX_LINES; i++)
    {
        if (fscanf(f_in, "%d;%*c;%*d/%d/%d;", codigo, &mes[i], &ano[i]) != 3)
            break;

        fscanf(f_in, "%*d"); fscanf(f_in, ";");
        fscanf(f_in, "%*f"); fscanf(f_in, ";");
        fscanf(f_in, "%*f"); fscanf(f_in, ";");
        fscanf(f_in, "%*d"); fscanf(f_in, ";");
        fscanf(f_in, "%*d"); fscanf(f_in, ";");
        fscanf(f_in, "%*d"); fscanf(f_in, ";");
        fscanf(f_in, "%*d"); fscanf(f_in, ";");
        fscanf(f_in, "%*d"); fscanf(f_in, ";");
        fscanf(f_in, "%*f"); fscanf(f_in, ";");
        fscanf(f_in, "%*f"); fscanf(f_in, ";");
        
        for (size_t l = 0; l < 31; l++)
        {
            if (fscanf(f_in, "%f;", &chuva[i][l]) != 1)
            {
                fscanf(f_in, ";");
            }
        }
        for (size_t l = 0; l < 31; l++)
        {
            if (fscanf(f_in, "%d;", &chuva_status[i][l]) != 1)
            {
                fscanf(f_in, ";");
            }
        }

        linhas++;
    }
    return linhas;
}

void print_entrada(size_t linhas, int codigo, int *mes, int *ano, float **chuva, int **chuva_status)
{
    printf("CODIGO: %d\n", codigo);
    for (size_t l = 0; l < linhas; l++)
    {
        printf("%02d/%d: ", mes[l], ano[l]);
        for (size_t i = 0; i < 31; i++)
        {
            if (chuva_status[l][i] == 1)
                printf("%6.1f", chuva[l][i]);
        }
        printf("\n");
    }
    
}