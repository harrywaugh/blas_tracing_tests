CC=CC

LIBS="-L/opt/allinea/19.2.0.0/opt/arm/armpl-19.2.0_ThunderX2CN99_SUSE-12_gcc_8.2.0_aarch64-linux/lib -larmpl_lp64_mp"
CFLAGS=-std=c++11

all:
	${CC} ${LLIBS} ${CFLAGS} dgemm_test.cpp -o dgemm_test.exe