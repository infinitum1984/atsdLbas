

#include <iostream>

using namespace std;

void mSwap(long long* a, long long* b);
void mergeSort(long long* mas, int size, long long l, long long r);

int main() {
    long long* array;
    int n;
    cout << "Enter n: ";   
    cin >> n;

    array = new long long[n];
    cout << "Enter array: ";
    for (int i = 0; i < n; i++)
        cin >> array[i];

    mergeSort(array,n,0, n - 1);
    cout << "\n\tSorted array\n";
    for (int i = 0; i < n; i++)
        cout << array[i] << " ";
    cout << endl;
    delete[] array;
    return 0;
}
void mSwap(long long* a, long long* b) {
   long long temp = *a;
    *a = (*b);
    *b = temp;
}
void mergeSort(long long* mas, int size, long long l, long long r) {


    if (r == l)
        return;
    if (r - l == 1) {
        if (mas[r] < mas[l])
            mSwap(&mas[r], &mas[l]);
        return;
    }
    long long m = (r + l) / 2;
    mergeSort(mas, size, l, m);
    mergeSort(mas, size, m + 1, r);
    long long* buf = new long long [size];
    long long xl = l;
    long long xr = m + 1;
    int cur = 0;
    while (r - l + 1 != cur) {
        if (xl > m)
            buf[cur++] = mas[xr++];
        else if (xr > r)
            buf[cur++] = mas[xl++];
        else if (mas[xl] > mas[xr])
            buf[cur++] = mas[xr++];
        else buf[cur++] = mas[xl++];

    }
    for (int i = 0; i < cur; i++)
        mas[i + l] = buf[i];
    delete[] buf;
}