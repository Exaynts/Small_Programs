#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> ratings {5, 6};
    sort(ratings.begin(), ratings.end());
    int answer = 1;
    int add_per_child = 1;
    if (ratings.size() == 1) { answer = 1;}
    else {
        for(int i = 1; i < ratings.size(); i ++) {
            if (ratings[i] != ratings[i-1]) {
                add_per_child += 1;
            }
            answer += add_per_child;
        }
    }
    cout << answer;
    return 0;
}
