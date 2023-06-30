#include <algorithm>
#include <cctype>
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
#include <unordered_set>
using namespace std;
class Solution
{
public:
    int dominantIndex(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        int index = 0, maxNum = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] > maxNum)
            {
                maxNum = nums[i];
                index = i;
            }
        }
        sort(nums.begin(), nums.end());
        if (nums[n - 1] >= 2 * nums[n - 2])
            return index;
        else
            return -1;
    }
};