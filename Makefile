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
${DIR_C}/%.o: ${DIR_C}/%.c ${DIR_C}/%.h
	$(CC) -c -o $@ $<

main_c: ${DIR_C}/main.o ${DIR_C}/entradas.o
	$(CC) -o $@ $? -Wall

# VERSAO FORTRAN
${DIR_FORTRAN}/%.o: ${DIR_FORTRAN}/%.f90
	$(FC) -c -o $@ $<

main_f: ${DIR_FORTRAN}/main.o ${DIR_FORTRAN}/entradas.o
	$(FC) -o $@ $?