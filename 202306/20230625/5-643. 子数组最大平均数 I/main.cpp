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
    double findMaxAverage(vector<int> &nums, int k)
    {
        // double max = 0.000;
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < k; i++)
        {
            sum += nums[i];
        }
        int maxSum = sum;
        for (int i = k; i < n; i++)
        {
            sum += nums[i] - nums[i - k];
            maxSum = max(maxSum, sum);
        }
        return static_cast<double>(maxSum) / k;
    }
};