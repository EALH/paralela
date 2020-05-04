#include <iostream>
#include <omp.h>

using namespace std;

int main(int argc, char* argv[])
{
    int n = atoi(argv[1]);
    double* x, y;

    x =  new double [n]; 
    for(int i = 0; i < n; i++)
    {
        x[i] = (double) (i + 2);
    }

    y =  new double [n]; 
    for(int i = 0; i < n; i++)
    {
        y[i] = (double) (i + 3);
    } 

    double start = omp_get_wtime();

    for (int i = 0; i < n; i++)
    {
        x[i] = x[i] + y[i];
    }
    double end = omp_get_wtime();
    printf("start = %.16g\nend = %.16g\ndiff = %.16g\n", start, end, end - start);
    return 0;
    
}

