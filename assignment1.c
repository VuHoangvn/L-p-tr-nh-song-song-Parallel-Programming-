#include<stdio.h>
#include<omp.h>
#include<malloc.h>
#define M 20

int main(){
    int i, *A, *B, *C, id, start, end;
    A = (int *) malloc(M*sizeof(int));
    B = (int *) malloc(M*sizeof(int));
    C = (int *) malloc(M*sizeof(int));
    for(int i = 0; i < M; i++){
        *(A+i) = i;
        *(B+i) = 2*i;
    }
    omp_set_num_threads(4);
    #pragma omp parallel private(id)
    {
        id = omp_get_thread_num();
        start = id*M/4;
        end = start + M/4;
        for(int i = start; i < end; i++){
            *(C+i) = *(A+i) + *(B+i);
        }
    }

    printf("A \t B \t C\n");
    for(int i = 0; i < M; i++){
        printf("%d \t %d \t %d\n", *(A+i), *(B+i), *(C+i));
    }

    free(A); free(B); free(C);

    return 0;
}