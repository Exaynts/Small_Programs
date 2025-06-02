#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int candy(vector<int>& ratings) {
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
            add_per_child -= 1;
        }
    }
    cout << answer;
    return answer;
    }
};
