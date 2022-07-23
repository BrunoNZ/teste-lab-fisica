PROGRAM main
   use entradas

   IMPLICIT NONE

   character(len=1024) :: arq_entrada
   character(len=10) :: d_x_str, d_y_str, d_t_str
   integer :: d_x, d_y, d_t
   type(bindata) :: bd

   call GET_COMMAND_ARGUMENT(1, arq_entrada)
   call GET_COMMAND_ARGUMENT(2, d_x_str)
   call GET_COMMAND_ARGUMENT(3, d_y_str)
   call GET_COMMAND_ARGUMENT(4, d_t_str)
   read(d_x_str, *) d_x
   read(d_y_str, *) d_y
   read(d_t_str, *) d_t

   call le_bindata(bd, arq_entrada, d_x, d_y, d_t)
   call print_bindata_txt(bd)
   call free_bindata(bd)

END program main