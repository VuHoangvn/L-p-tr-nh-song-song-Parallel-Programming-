// khoi tao A[100], B[100]
// tai rank = 0
// Mc = 100 / p
// tinh C = A + B
// tren P process (100 % P = 0)
// tap hop ket qua ve rank 0 va in ra man hinh
// rank 0 -> rank N
#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int rank, size;
    int np = 10;
    int sub = 10;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Status stat;
    int Ac = (int *)malloc(10 * sizeof(int));
    int Bc = (int *)malloc(10 * sizeof(int));
    int Cc = (int *)malloc(10 * sizeof(int));
    if (rank == 0)
    {
        int *A = (int *)malloc(100 * sizeof(int));
        int *B = (int *)malloc(100 * sizeof(int));
        int *C = (int *)malloc(100 * sizeof(int));
        for (int i = 0; i < 100; i++)
        {
            A[i] = i;
            B[i] = i;
        }
        for(int i = 0; i < 10; i++){
            C[i] = A[i] + B[i];
        }

    }

    printf("rank: %d\n", rank);

    MPI_Finalize();
    return 0;
}
