#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "entradas.h"

void free_bindata(bindata bd)
{
    free(bd.val);
}

bindata le_bindata(const char *arq_entrada, int d_x, int d_y, int d_t)
{
    bindata bd;
    FILE *f_in;

    bd.d_x = (size_t)d_x;
    bd.d_y = (size_t)d_y;
    bd.d_t = (size_t)d_t;
    bd.undef = -999.0;
    bd.total_dim = (bd.d_x * bd.d_y * bd.d_t);
    bd.total_size = bd.total_dim * sizeof(float);
    bd.val = (float *)malloc(bd.total_size);

    f_in = fopen(arq_entrada, "rb");
    fread(bd.val, sizeof(float), bd.total_dim, f_in);
    fclose(f_in);

    return bd;
}

size_t get_pos(bindata bd, size_t x, size_t y, size_t t)
{
    return (x + bd.d_x * (y + bd.d_y * t));
}

void print_bindata_txt(bindata bd)
{
    size_t pos;
    for (size_t x = 0; x < bd.d_x; x++)
    {
        for (size_t y = 0; y < bd.d_y; y++)
        {
            for (size_t t = 0; t < bd.d_t; t++)
            {
                pos = get_pos(bd, x, y, t);
                if (bd.val[pos] != bd.undef){
                    printf("[%3ld,%3ld,%5ld] %10.6f\n", (x+1), (y+1), (t+1), bd.val[pos]);
                }
            }
        }
    }
}