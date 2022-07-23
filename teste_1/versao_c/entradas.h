#ifndef _ENTRADAS_H_
#define _ENTRADAS_H_

typedef struct
{
    float undef;
    float *val;
    size_t d_x, d_y, d_t;
    size_t total_dim;
    size_t total_size;
} bindata;

void free_bindata(bindata bindata);
bindata le_bindata(const char *arq_entrada, int d_x, int d_y, int d_t);
size_t get_pos(bindata bindata, size_t x, size_t y, size_t t);
void print_bindata_txt(bindata bindata);

#endif