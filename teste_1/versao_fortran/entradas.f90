module entradas
   implicit none
   public bindata
   type bindata
      integer :: d_x, d_y, d_t
      real, dimension(:,:,:), allocatable :: val
      real :: undef
      integer :: total_dim
   end type
   
contains

subroutine le_bindata(bd, arq_entrada, d_x, d_y, d_t)
   IMPLICIT NONE

   character(*), intent(in) :: arq_entrada
   integer, intent(in) :: d_x, d_y, d_t
   type(bindata), intent(out) :: bd
   integer :: x,y,t
   
   bd%d_x = d_x
   bd%d_y = d_y
   bd%d_t = d_t
   bd%undef = -999.0
   bd%total_dim = bd%d_x * bd%d_y * bd%d_t
   allocate(bd%val(bd%d_x, bd%d_y, bd%d_t))

   open(1, file = arq_entrada, status = 'OLD', FORM='UNFORMATTED', ACCESS='DIRECT', RECL=(bd%d_x * bd%d_y * 4))
   do t = 1, bd%d_t
      read(1, rec=t) ((bd%val(x,y,t), x=1, bd%d_x), y=1, bd%d_y)
   end do
   close(1)
end subroutine le_bindata

subroutine print_bindata_txt(bd)
   type(bindata), intent(in) :: bd
   integer :: x,y,t

   do x = 1, bd%d_x
      do y = 1, bd%d_y
         do t = 1, bd%d_t
            if ( bd%val(x,y,t) .ne. bd%undef ) then
               print('(A1,I3,A1,I3,A1,I5,A1,1X,F10.6)'), "[", x, ",", y, ",", t, "]", bd%val(x,y,t)
            end if
         end do
      end do   
   end do
end subroutine
   
end module entradas

