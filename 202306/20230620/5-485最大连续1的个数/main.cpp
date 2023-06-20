#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxCount = 0, count = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                count++;
            } else {
                maxCount = max(maxCount, count);
                count = 0;
            }
        }
        maxCount = max(maxCount, count);
        return maxCount; 
    }
};
//双指针思路
int findMaxConsecutiveOnes(vector<int>& nums) {
    int n = nums.size();
    int max = 0;
    for (int i = 0; i < n; i++) {
        int j = i;
        while (j < n && nums[j] == 1) j++;
        max = max > j - i ? max : j - i;
        i = j;
    }
    return max;
}
int main() {
    Solution s;
    vector<int> nums = {1, 1, 0, 1, 1, 1};
    int res = s.findMaxConsecutiveOnes(nums);
    cout << res << endl;
    return 0;
}