#include <random>
#include <armpl.h>
//#include <cblas.h>
#include <omp.h>
#include <iostream>

using namespace std;

int main ( int argc, char* argv[]) {

#pragma omp parallel
    {
   
    int work_threads;

#pragma omp for private(work_threads)
    for (work_threads = 0; work_threads < 16; work_threads++)  {
        cout << "Calculating matmul " << work_threads << endl;
        
        std::mt19937_64 rnd;
        std::uniform_real_distribution<double> doubleDist(0, 1);
        const int n = 150;

        double*  A = new double[n*n];
        double*  C = new double[n*n];

        // Fill A with random numbers
        for(uint i = 0; i <n*n; i++){
            A[i] = doubleDist(rnd);
        }

        for (int i=0; i < 1000; i++)  {
        	// For symmetric matrix B
        	cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasTrans, n, n, n, 1.0, A, n, A, n, 0.0, C, n);
                printf("DGEMM Out!\n");

        	for(uint i = 0; i < n; i++)
        		C[i+i*n] +=100.0;

        	const char uplo = 'U';
        	int info;
                // Calculate A * B = C
                dpotrf_(&uplo, &n, C, &n, &info);
                printf("DPOTRF Out!\n");
        }

        // Clean up
        cout << "Exiting " << work_threads << endl;
        delete[] A;
        delete[] C;
    }
    }

    return 0;
}
