#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// template <typename T>
// void swap1(T a, T b) {
//     T tmp = a;
//     b = a;
//     a = tmp;
// }
class Solution {
public:
template <typename T>
void swap1(T a, T b) {
    T tmp = a;
    b = a;
    a = tmp;
}
    void reverseString(vector<char>& s) {
        int n = s.size();
        //交换的守法 看清楚
        for (int left = 0, right = n - 1; left < right; left++, right--) {
            swap(s[left], s[right]);
        }
    }
};