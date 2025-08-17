// 12345678910111213141516...
// find digit in k posision
// with q requests. 1 request gives 1 digit
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

// Ввод числа
int Input() {
    int input;
    while (!(cin >> input) or (cin.peek() != '\n')) {
        cin.clear();
        while (cin.get() != '\n');
        cout << "Enter the number correctly!" << endl;
    }
    cin.ignore();
    return input;
}
// Ввод списка из q чисел
vector <int> Input_list(vector <int>& Query, int q) {
    for (int i = 0; i < q; i++) {
        cout << "list[" << i << "] = ";
        Query[i] = Input();
    }
    return Query;
}
// Находим нужную цифру на k-ой позиции
int find_digit(int k) {
    // Пропускаем номера всех чисел, длиной ниже искомого и узнаём длину целевого числа
    int pre_low = 0; int low = 0; int len = 0;
    while (low < k) {
        len += 1;
        pre_low = low;
        low += len * 9 * pow(10, len - 1);
    }
    low = pre_low;
    // Номер нужного подчисла в списке чисел с длиной len
    int target_number = (k - low-1) / len + pow(10, len - 1);
    // Порядок цифры в нужном подчисле
    int target_place;
    if ((k - low) % len == 0)
        target_place = len;
    else
        target_place = (k - low) % len;
    // Получение целевой цифры числа путём отбразывания лишних цифр с конца
    while (target_number >= pow(10, target_place)) {
        target_number /= 10; // Отбрасываем последнюю цифру, пока не останется нужное их количество
    }
    int digit = target_number % 10;
    return digit;
}
// Точка входа в программу
int main() {
    // Ввод числа q
    cout << "q = ";
    int q = Input();
    // Ввод списка из q чисел
    vector <int> Query(q);
    Query = Input_list(Query, q);
    // Определяем нужные цифры по запросам
    vector <int> Return(q);
    for (int i = 0; i < q; i++) {
        Return[i] = find_digit(Query[i]);
    }
    // Вывод искомых цифр
    for (int i = 0; i < q; i++) {
        cout << Return[i] << endl;
    }
    return 0;
}
