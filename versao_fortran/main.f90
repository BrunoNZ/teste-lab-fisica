PROGRAM main
   IMPLICIT NONE

   integer :: codigo
   real, dimension(256,31) :: chuva, chuva_status
   integer, dimension(256) :: mes, ano
   integer :: i

   open(1, file = 'chuvas_T_00048002.txt', status = 'OLD', form = 'FORMATTED')

   do i = 1, 13
      read(1, *)      
   end do

   read(1, '(I5,A6,I2,A1,I2)') codigo, mes(1), ano(1)
   print *, codigo, mes(1), ano(1)
   
END
