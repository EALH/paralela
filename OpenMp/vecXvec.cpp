#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <omp.h>
#include <math.h>

using namespace std;

float* lee_vec(char *, int);
float* crea_vec(int);

int main(int argc, char ∗ argv[])
{ 
    int i, n;
    float prod = 0.0;
    float* v1, v2;

    omp_set_num_threads(8);
    n = atoi(argv[3]);
    v1 = new float[n];
    v2 = new float[n];
    
    v1 = lee_vec(argv[1], n);
    v2 = lee_vec(argv[2], n);

    #pragma omp for reduction(+ : sum) 
    for (i = 0; i < n; i + +){
        prod += v1[i] ∗ v2[i]; 
    }
    cout<<"El producto es igual a: "<<prod<<endl;
    return 0;
}