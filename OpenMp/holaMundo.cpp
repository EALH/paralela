#include <iostream>
#include <omp.h>

using namespace std;

int main(int argc, char ∗ argv[])
{ 
    omp_set_num_threads(8);

    #pragma omp parallel
    {
        cout<<"Hola mundo con mp"<<endl;
    }

    return 0;
}