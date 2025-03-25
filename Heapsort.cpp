#include <iostream>
#include <vector>
using namespace std;

// Выстраивание элементов массива в виде сортирующего дерева
void Tree(vector <int> A, int n) {
    // Для i = 2*i + 1
    int i = 0;
    while (i < n/2) {
        if (A[i] > A[2*i+1]) {
            swap(A[i], A[2*i+1]);
            i = i*2+1;
        }
    }
    // Для i = 2*i + 2
    i = 0;
    while (i < ((n-2)/2)) {
        if (A[i] > A[2*i+2]) {
            swap(A[i], A[2*i+2]);
            i = i*2+2;
        }
    }
}

int main() {
// Определение массива
int n = 8;
vector <int> A(n);
A = {1, 10, 13, 15, 8, 2, 3, 4};
// Этап 1.
for(int j = 0; j < n; j++) {
    Tree(A, n); }
// Этап 2.
for(int j = 1; j < n; j++) {
    swap(A[0], A[n-j]);
    Tree(A, n); }
// Вывод массива
for(int i = 0; i < n; i++) {
    cout << A[i] << " "; }
return 0;
}
