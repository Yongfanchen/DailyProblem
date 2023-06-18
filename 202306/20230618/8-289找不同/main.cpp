#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
using namespace std;
class Solution {
public:
    char findTheDifference(string s, string t) {
        for (auto ch : s) {
            size_t res = t.find(ch);
            if (res != string::npos) {
                t.erase(res, 1);
            }
        }
        return t[0];
    }
};