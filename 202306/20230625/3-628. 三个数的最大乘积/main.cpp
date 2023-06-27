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
    int maximumProduct(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int maxNumright = nums[n - 1] * nums[n - 2] * nums[n - 3];
        int maxNumleft = 0;
        if (nums[0] < 0 && nums[1] < 0)
        {
            maxNumleft = nums[0] * nums[1] * nums[n - 1];
        }
        return max(maxNumright, maxNumleft);
    }
};