#include <iostream>
#include <omp.h>

using namespace std;

int main(int argc, char* argv[])
{
    double start = omp_get_wtime();
    if(!omp_in_parallel())
    {
        printf("Número de procesos: %d\n", omp_get_num_procs());
        printf("Número máximo de hilos: %d\n", omp_get_max_threads());
    }

    sleep(1);
    double end = omp_get_wtime();
    printf("start = %.16g\nend = %.16g\ndiff = %.16g\n", start, end, end - start);
    return 0;
}