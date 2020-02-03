CC=CC

LIBS="-L/opt/allinea/19.2.0.0/opt/arm/armpl-19.2.0_ThunderX2CN99_SUSE-12_gcc_8.2.0_aarch64-linux/lib -larmpl"
CFLAGS= -h dynamic
#CFLAGS=-std=c++11

serial:
	${CC} ${LLIBS} ${CFLAGS} dgemm_test.cpp -o dgemm_test.exe

mpi:
	${CC} ${LLIBS} ${CFLAGS} dgemm_test_mpi.cpp -o dgemm_test_mpi.exe

openmp:
	${CC} ${LLIBS} ${CFLAGS} dgemm_test_openmp.cpp -o dgemm_test_openmp.exe

openmp-dpotrf:
	${CC} ${LLIBS} ${CFLAGS} -fopenmp -g dpotrf_test_openmp.cpp -o dpotrf_test_openmp.exe
clean:
	rm -rf *.exe *.job.*
