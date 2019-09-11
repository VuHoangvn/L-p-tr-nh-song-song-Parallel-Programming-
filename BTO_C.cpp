#include <iostream>

using namespace std;

int* create_array(int n){
    int *a = new int[n];
    for(int i = 0; i < n; i++){
        a[i] = i;
    }
    return a;
}

int* sum_to_array(int* a, int* b, int size){
    int *sum = new int[size];
    for(int i = 0; i < size; i++){
        sum[i] = a[i] + b[i];
        cout<< sum[i] << " ";
    }

    return sum;
}
int main() {
    int n = 10;
    int *a = create_array(n);
    int *b = create_array(n);
    int *c = sum_to_array(a, b, n);

    delete a; delete b; delete c;
    return 0;
}