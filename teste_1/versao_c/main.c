#include <stdio.h>
#include <stdlib.h>
#include "entradas.h"

int main(int argc, char const *argv[])
{
    bindata bindata;

    bindata = le_bindata(argv[1], atoi(argv[2]), atoi(argv[3]), atoi(argv[4]));
    print_bindata_txt(bindata);

    free_bindata(bindata);

    return 0;
}

