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

    
    // Random numbers
    std::mt19937_64 rnd;
    std::uniform_real_distribution<double> doubleDist(0, 1);
 
    for (uint k = 5; k <= 106; k += 50)  {
        for (uint m = 1; m <= 101; m += 50)  {
    
            // Create arrays that represent the matrices A,B,C
            // const int m = 20;
            //const int k = 5;
            const int n = 150;
            
            double*  A = new double[m*k];
            double*  B = new double[n*k];
            double*  C = new double[m*n];

            // Fill A and B with random numbers
            for(uint i =0; i <m*k; i++){
                A[i] = doubleDist(rnd);
            }
        
            for(uint i =0; i <k*n; i++){
                B[i] = doubleDist(rnd);
            }

            for (int i=0; i < 1000; i++)  {
                // Calculate A*B=C
                cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, m, n, k, 1.0, A, k, B, n, 0.0, C, n);
            }

            // Clean up
            delete[] A;
            delete[] B;
            delete[] C;
        }
    }

    MPI_Finalize();

    return 0;
}
