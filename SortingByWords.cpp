#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

// Разбиение строк по словам
vector<string> Spliting(string S) {
    vector<string> S_split;
    string word;
    stringstream ss(S);
    while(ss >> word) {
        S_split.push_back(word);
    }

    return S_split;
}

// Соединение строк
vector<string> Concatenation(vector<string> S1_split, vector<string> S2_split) {
    vector<string> S12;
    int S1Size = S1_split.size();
    int S2Size = S2_split.size();
    for (int i = 0; i < S1Size; i++) {
        S12.push_back(S1_split[i]);
    }
    for (int j = 0; j < S2Size; j++) {
        S12.push_back(S2_split[j]);
    }
    return S12;
}

// Соединение слов в строку
string Concatenation(vector<string> S12_split) {
    string S12;
    for (int i = 0; i < S12_split.size(); ++i) {
        S12 += S12_split[i];
        S12 += " ";
    }
    return S12;
}

int main() {
    // Ввод строк
    cout << "Sentence 1: ";
    string S1;
    getline(cin, S1);
    cout << "Sentence 2: ";
    string S2;
    getline(cin, S2);
    // Разбиение строк по словам
    vector<string> S1_split = Spliting(S1);
    vector<string> S2_split = Spliting(S2);
    // Соединение строк
    vector<string> S12_split = Concatenation(S1_split, S2_split);
    // Сортировка строки
    sort(S12_split.begin(), S12_split.end());
    // Соединение слов в строку
    string S12 = Concatenation(S12_split);
    // Вывод строки
    cout << "Sorted_string: " << S12 << endl;

    return 0;
}
