#ifndef _ENTRADAS_H_
#define _ENTRADAS_H_

#include <locale.h>

#define MAX_LINES 256

void aloca_entradas(int **mes, int **ano, float ***chuva, int ***chuva_status);
void free_entradas(size_t linhas, int **mes, int **ano, float ***chuva, int ***chuva_status);
int le_entrada(const char *arq_entrada, int *codigo, int *mes, int *ano, float **chuva, int **chuva_status);
void print_entrada(size_t linhas, int codigo, int *mes, int *ano, float **chuva, int **chuva_status);

#endif