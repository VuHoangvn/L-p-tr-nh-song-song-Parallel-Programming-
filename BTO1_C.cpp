#include <iostream>

using namespace std;

int** create_matrix(int row, int col){
    int **a = new int*[row * col];
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            a[i][j] = i+j;
        }
    }

    return a;
}

int** mul_matrix(int** a, int** b, int m, int n, int p){
    int** mul = new int*[m * p];

    for(int i = 0; i < m; i++){
        for(int j = 0; j < p; j++){
            mul[i][j] = 0;
            // for(int k = 0; k < n; k++){
            //     mul[i][j] += a[i][k] * b[k][j];
            // }
            cout<< mul[i][j] << " ";
        }
    }

    return mul;
}
int main(){
    int m = 4;
    int n = 5; 
    int p = 4;
    int** a = create_matrix(m, n);
    int** b = create_matrix(n, p);
    int** c = mul_matrix(a, b, m, n, p);

    delete a; delete b; delete c;
    return 0;
}