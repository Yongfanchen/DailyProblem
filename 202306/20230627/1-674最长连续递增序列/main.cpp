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
  int findLengthOfLCIS(vector<int> &nums) {
    int n = nums.size();
    int maxCount = 0;
    int start = 0;
    for (int i = 0; i < n; i++) {
      if (i > 0 && nums[i] <= nums[i - 1])
        start = i;
      maxCount = max(maxCount, i - start + 1);
    }
    return maxCount;
  }
};

class Solution1 {
public:
  int findLengthOfLCIS(vector<int> &nums) {
    int n = nums.size();
    int ans = 0;
    int count = 1;
    for (int i = 0; i < n - 1; i++) {
      if (nums[i + 1] > nums[i])
        count++;
      else
        count = 1;
      ans = max(ans, count);
    }
    return ans;
  }
};