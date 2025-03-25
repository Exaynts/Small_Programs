#include <iostream>
#include <vector>
using namespace std;

void print(vector <int>&A, int n) {
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}
// Выстраивание элементов массива в виде сортирующего дерева
void Tree(vector <int> &A, int n, int k) {
    // Для i = 2*i + 1
    int i = k;
    while ((2*i+1) < n) {
        if (A[i] < A[2 * i + 1]) {
            swap(A[i], A[2 * i + 1]);
            print(A, n);
        }
        i = i * 2 + 1;
    }
    // Для i = 2*i + 2
    i = k;
    while ((2*i+2) < n) {
        if (A[i] < A[2 * i + 2]) {
            swap(A[i], A[2 * i + 2]);
            print(A, n);
        }
        i = i * 2 + 2;
    }
}

int main() {
    // Определение массива
    int n = 5;
    vector <int> A(n);
    //A = { 2, 10, 1, 13, 15, 8, 12, 4, 25, 28, 9, 22 };
    //A = {1, 2, 3, 4};
    A = {3, 1, 5, 2, 6};
    // Этап 1.
    for (int j = 0; j < n; j++) {
        Tree(A, n, j);
    }
    print(A, n);
    // Этап 2.
    cout << "--" << endl;
    for (int j = 1; j <= n; j++) {
        swap(A[0], A[n - j]);
        cout << "j = " << j << endl;
        for (int k = 0; k < n-j; k++) {
            Tree(A, n, k);
        }
    }
    // Вывод массива
    cout << "---" << endl;
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    return 0;
}
