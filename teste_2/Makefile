FC=gfortran
DIR_C=./versao_c
DIR_FORTRAN=./versao_fortran

all: c fortran

c: main_c
fortran: main_f

clean:
	-find . -iname "*.o" -exec rm {} \;
	-find . -iname "*.mod" -exec rm {} \;
	-find . -iname "main_[cf]" -exec rm {} \;

# VERSAO C
${DIR_C}/%.o: ${DIR_C}/%.c
	$(CC) -c -o $@ $< -Wall

main_c: ${DIR_C}/entradas.o ${DIR_C}/main.o
	$(CC) -o $@ $?

# VERSAO FORTRAN
${DIR_FORTRAN}/%.o: ${DIR_FORTRAN}/%.f90
	$(FC) -c -o $@ $< -I${DIR_FORTRAN}

main_f: ${DIR_FORTRAN}/entradas.o ${DIR_FORTRAN}/main.o
	$(FC) -o $@ $?