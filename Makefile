CC=CC
FC=ftn

MPICC=mpicc


ARM_LIBS=-L${ARMPL_LIBRARIES} -larmpl -lamath 
CRAY_LIBS="-L/opt/cray/pe/libsci/18.12.1/CRAY/8.6/aarch64/lib -lsci_cray -h dynamic "

serial:
	${CC} ${ARM_LIBS}  src/dgemm_test.cpp -o dgemm_test.exe

mpi:
	${CC} ${ARM_LIBS} src/dgemm_test_mpi.cpp -o dgemm_test.exe

openmp:
	${CC} ${ARM_LIBS} ${CFLAGS} src/dgemm_test_openmp.cpp -o dgemm_test.exe

openmp-dpotrf:
	${CC} ${ARM_LIBS} ${CFLAGS} -fopenmp -g src/dpotrf_test_openmp.cpp -o dpotrf_test.exe

fort-blas:
	${FC} ${ARM_LIBS} src/fortran_blas1.f90 -o fortran_blas.exe

clean:
	rm -rf *.exe *.job.*
