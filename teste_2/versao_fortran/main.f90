PROGRAM main
   IMPLICIT NONE

   integer :: codigo
   real, dimension(256,31) :: chuva, chuva_status
   integer, dimension(256) :: mes, ano
   integer :: linhas

   call le_entrada("exemplo.txt", codigo, mes, ano, chuva, chuva_status, linhas)
   call print_entrada(codigo, mes, ano, chuva, chuva_status, linhas)

END program main