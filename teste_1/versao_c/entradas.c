#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "entradas.h"

void free_bindata(bindata bindata)
{
    free(bindata.val);
}

bindata le_bindata(const char *arq_entrada, int d_x, int d_y, int d_t)
{
    bindata bindata;
    FILE *f_in;

    bindata.d_x = (size_t)d_x;
    bindata.d_y = (size_t)d_y;
    bindata.d_t = (size_t)d_t;
    bindata.undef = -999.0;
    bindata.total_dim = (bindata.d_x * bindata.d_y * bindata.d_t);
    bindata.total_size = bindata.total_dim * sizeof(float);
    bindata.val = (float *)malloc(bindata.total_size);

    f_in = fopen(arq_entrada, "rb");
    fread(bindata.val, sizeof(float), bindata.total_dim, f_in);
    fclose(f_in);

    return bindata;
}

size_t get_pos(bindata bindata, size_t x, size_t y, size_t t)
{
    return (x + bindata.d_x * (y + bindata.d_y * t));
}

void print_bindata_txt(bindata bindata)
{
    size_t pos;
    for (size_t x = 0; x < bindata.d_x; x++)
    {
        for (size_t y = 0; y < bindata.d_y; y++)
        {
            for (size_t t = 0; t < bindata.d_t; t++)
            {
                pos = get_pos(bindata, x, y, t);
                if (bindata.val[pos] != bindata.undef){
                    printf("[%ld,%ld,%ld] (%ld) = %f\n", x, y, t, pos, bindata.val[pos]);
                }
            }
        }
    }
}