  program dot_main
    complex x(10), y(10), zdotc, res
    integer n, incx, incy, i
    external zdotc
    n = 5
    incx = 2
    incy = 1
    do i = 1, 10
      x(i) = (2.0, 1.0)
      y(i) = (1.0, 1.0)
    end do
    res = zdotc(n, x, incx, y, incy)
    write(*,*) "Done!"
  end
