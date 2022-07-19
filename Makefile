FC=gfortran
DIR_C=./versao_c
DIR_FORTRAN=./versao_fortran

all: c fortran

c: main_c
fortran: main_f

clean:
	-find . -iname "*.o" -exec rm {} \;
	-find . -iname "main_[cf]" -exec rm {} \;

# VERSAO C
entradas.o: ${DIR_C}/entradas.c ${DIR_C}/entradas.h
	$(CC) -c -o $@ $<

main_c: ${DIR_C}/main.c entradas.o
	$(CC) -o $@ $? -Wall

# VERSAO FORTRAN
main_f: ${DIR_FORTRAN}/main.f90
	$(FC) -o $@ $?