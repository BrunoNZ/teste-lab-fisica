subroutine le_entrada(arq_entrada, codigo, mes, ano, chuva, chuva_status, linhas)
   IMPLICIT NONE

   character(*), intent(in) :: arq_entrada
   integer, intent(inout) :: codigo
   integer, dimension(256), intent(inout) :: mes, ano
   real, dimension(256,31), intent(inout) :: chuva, chuva_status
   integer, intent(out) :: linhas
   integer :: i, l, iostatus

   ! BUFFERS:
   character(len=1024) :: buf
   real :: bf
   integer :: bi

   open(1, file = arq_entrada, status = 'OLD', form = 'FORMATTED')

   do i = 1, 13
      read(1, *)      
   end do

   linhas = 0
   do i = 1, 256
      read(1, '(I5,6X,I2,1X,I4,1X,A256)', iostat=iostatus) codigo, mes(i), ano(i), buf
      IF (iostatus > 0) THEN
         EXIT
      END IF

      read(buf, *, DECIMAL='COMMA') bi, bf, bf, bi, bi, bi, bi, bi, bf, bf, (chuva(i, l), l=1, 31), (chuva_status(i, l), l=1, 31)
   
      linhas = linhas + 1      
   end do
end subroutine le_entrada

subroutine print_entrada(codigo, mes, ano, chuva, chuva_status, linhas)
   integer, intent(in) :: codigo
   integer, dimension(256) :: mes, ano
   real, dimension(256,31) :: chuva, chuva_status
   integer, intent(out) :: linhas

   print '(A8, I5)', "CODIGO: ", codigo
   do i = 1, linhas - 1
      write(*, '(I0.2,A1,I4,A2)',  advance="no") mes(i), "/", ano(i), ": "
      do l = 1, 31
         if ( chuva_status(i,l) == 1 ) then
            write(*, '(F6.1)', advance="no", DECIMAL='COMMA') chuva(i,l)
         end if
      end do
      print *, ""
   end do
end subroutine