#include <algorithm>
#include <cctype>
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
 public:
  bool isHalfString(string s) {
    int sum = 0;
    int n = s.size();
    for (int i = 0; i < n; i++) {
      if (s[i] == '1') sum++;
    }
    return sum == n / 2;
  }
  int countBinarySubstrings(string s) {
    vector<int> counts;
    int ptr = 0, n = s.size();
    while (ptr < n) {
      char c = s[ptr];
      int count = 0;
      while (ptr < n && s[ptr] == c) {
        ++ptr;
        ++count;
      }
      counts.push_back(count);
    }
    int ans = 0;
    for (int i = 1; i < counts.size(); ++i)
      ans += min(counts[i], counts[i - 1]);
    return ans;
  }
};