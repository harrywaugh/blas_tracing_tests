#include <random>
<<<<<<< HEAD:src/dgemm_test.cpp
#include <armpl.h>
//#include <cblas.h>
=======
#include <mkl.h>
>>>>>>> 11ad13311730a4384d26845f9ab6f85301f23b06:dgemm_test.cpp
#include <sys/time.h>

// Get the current time in seconds since the Epoch
double wtime(void) {
  struct timeval tv;
  gettimeofday(&tv, NULL);
  return tv.tv_sec + tv.tv_usec*1e-6;
}

int main ( int argc, char* argv[] ) {
    
    double main_tic = wtime();


    // Random numbers
    std::mt19937_64 rnd;
    std::uniform_real_distribution<double> doubleDist(0, 1);

    // Create arrays that represent the matrices A,B,C
    const int m = 20;
    const int n = 150;
    const int k = 5;
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

    for (int i=0; i < 50000; i++)  {
        // Calculate A*B=C
        cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, m, n, k, 1.0, A, k, B, n, 0.0, C, n);
        //dgemm_(m, n, k, 1.0, A, k, B, n, 0.0, C, n);
    }    

    // Clean up
    delete[] A;
    delete[] B;
    delete[] C;

        
    double main_toc = wtime();
    main_toc -= main_tic;
    printf("Main function time: %.3f\n", main_toc);

    return 0;
}
