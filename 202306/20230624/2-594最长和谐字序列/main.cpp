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
    int findLHS(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int maxLength = 0;
        for (int i = 0, j = 0; j < n; j++)
        {
            while (i < j && nums[j] - nums[i] > 1)
                i++;
            if (nums[j] - nums[i] == 1)
                maxLength = max(maxLength, j - i + 1);
        }
        return maxLength;
    }
};
class Solution0
{
public:
    int findLHS(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int begin = 0;
        int res = 0;
        for (int end = 0; end < nums.size(); end++)
        {
            while (nums[end] - nums[begin] > 1)
                begin++;
            if (nums[end] - nums[begin] == 1)
                res = max(res, end - begin + 1);
        }
        return res;
    }
};