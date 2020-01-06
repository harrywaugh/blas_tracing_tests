#include <random>
//#include <armpl.h>
#include <cblas.h>
#include "mpi.h"

int main ( int argc, char* argv[]) {

    
    int size, rank, flag;

    //MPI Setup
    MPI_Init( &argc, &argv );
    MPI_Initialized(&flag);
    if ( flag != 1) {
        MPI_Abort(MPI_COMM_WORLD,EXIT_FAILURE);
    }
    MPI_Comm_size( MPI_COMM_WORLD, &size );
    MPI_Comm_rank( MPI_COMM_WORLD, &rank );

    
	std::mt19937_64 rnd;
	std::uniform_real_distribution<double> doubleDist(0, 1);
	const int n = 150;
	uint k = 105;
	uint m = 101;

	double*  A = new double[m*k];
	double*  B = new double[n*k];
	double*  C = new double[m*n];

	int m_dims[3] = {1, 51, 55};
	int k_dims[3] = {5, 55, 105};

	// Fill A and B with random numbers
	for(uint i = 0; i <m*k; i++){
		A[i] = doubleDist(rnd);
	}

	for(uint i =0; i <k*n; i++){
		B[i] = doubleDist(rnd);
	}

	for (k = 0; k < 3; k++)  {
		for (m = 0; m < 3; m++)  {
			for (int i=0; i < 1000; i++)  {
				// Calculate A * B = C
				cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, m_dims[m], n, k_dims[k], 1.0, A, k_dims[k], B, n, 0.0, C, n);
			}

		}
	}

	// Clean up
	delete[] A;
	delete[] B;
	delete[] C;
    MPI_Finalize();

    return 0;
}
