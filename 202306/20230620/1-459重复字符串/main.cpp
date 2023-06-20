#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    //思路：如果要完成题中要求，那么满足两个条件
    //1，字符串的长度可以整除子串的长度
    //2，每相隔字符串的举例的每两个字符要相等
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        for (int i = 1; i * 2 <= n; i++) {
            bool match = true;
            if (n % i == 0) {
                for (int j = i; j < n; j++) {
                    if (s[j] != s[j - i]) {
                        match = false;
                        break;
                    }
                }
                if (match) {
                    return true;
                }
            }
        }
        return false;
    }
};