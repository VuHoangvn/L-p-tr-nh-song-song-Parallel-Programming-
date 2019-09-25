#include <iostream>
#include <omp.h>

using namespace std;

int *generateArray(int m)
{
    int *arr = new int[m];
    int sum = 0;
    for (int i = 0; i < m; i++)
    {
        arr[i] = i;
        sum += i;
    }

    cout << "Sum: " << sum << endl;
    return arr;
}

int sumArr(int *arr, int m)
{
    if (m == 1)
        return arr[0];
    int id;
    if (m % 2 == 1)
        arr[m - 2] = arr[m - 1] + arr[m - 2];
    omp_set_num_threads(m / 2);
    #pragma omp parallel private(id)
    {
        id = omp_get_thread_num();
        arr[id] = arr[id] + arr[id+m/2];
    }
    m = m / 2;
    return sumArr(arr, m);
}

int main()
{
    int m;
    cout << "Input array size: ";
    cin >> m;
    // cout << m/2 << endl;
    int *arr = generateArray(m);
    cout << sumArr(arr, m) << endl;
    return 0;
}