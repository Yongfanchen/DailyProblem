#include <iostream>
using namespace std;
#include <vector>
#include <string>
// 先写思路
// 从位置0出发，向右遍历。每次遇到响铃元素之间的差值大于1时，我们就找到了一个区间。遍历完数组之后，就能得到一系列的区间的表
// 也要仔细看题，题中是否有重复元素等 你要搞清楚
vector<string> summaryRanges(vector<int> &nums)
{
    vector<string> res;
    int i = 0;
    int n = nums.size();
    while (i < n)
    {
        int low = i;
        i++;
        while (i < n && nums[i] == nums[i - 1] + 1)
        {
            i++;
        }
        int high = i - 1;
        string temp = to_string(nums[low]);
        if (low < high)
        {
            temp.append("->");
            temp.append(to_string(nums[high]));
        }
        res.push_back(temp);
    }
    return res;
}
int main()
{
}

vector<string> sum(vector<int> &nums)
{
    int i = 0;
    int n = nums.size();
    vector<string> res;
    while (i < n)
    {
        int low = i;
        i++;
        while (i < n && nums[i] == nums[i - 1] + 1)
        {
            i++;
        }
        int high = i - 1;
        string temp = to_string(nums[low]);
        if (low < high)
        {
            temp.append("->");
            temp.append(to_string(nums[high]));
        }
        res.push_back(temp);
        }
    return res;
}