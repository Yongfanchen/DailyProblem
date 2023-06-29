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
    bool indexsum(vector<int> &nums, int index)
    {
        int n = nums.size();
        int suml = 0, sumr = 0;
        for (int i = 0; i < index; i++)
            suml += nums[i];
        for (int i = index + 1; i < n; i++)
            sumr += nums[i];
        if (suml == sumr)
            return true;
        else
            return false;
    }
    int pivotIndex(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (indexsum(nums, i))
                return i;
        }
        return -1;
    }
};

int pivotIndex(vector<int> &nums)
{
    int total = 0;
    for (auto &num : nums)
        total += num;
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (sum == total - sum - nums[i])
        {
            return i;
        }
        sum += nums[i];
    }
    return -1;
}