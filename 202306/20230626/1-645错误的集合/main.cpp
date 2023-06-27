#include <algorithm>
#include <cctype>
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
#include <unordered_set>
using namespace std;
/*
645. 错误的集合
集合 s 包含从 1 到 n 的整数。不幸的是，因为数据错误，导致集合里面某一个数字复制了成了集合里面的另外一个数字的值，导致集合 丢失了一个数字 并且 有一个数字重复 。

给定一个数组 nums 代表了集合 S 发生错误后的结果。

请你找出重复出现的整数，再找到丢失的整数，将它们以数组的形式返回。

示例 1：

输入：nums = [1,2,2,4]
输出：[2,3]
示例 2：

输入：nums = [1,1]
输出：[1,2]
*/
class Solution
{
public:
	vector<int> findErrorNums(vector<int> &nums)
	{
		unordered_map<int, int> hashmap;
		for (auto & num : nums)
		{
			hashmap[num]++;
		}
		vector<int> res(2);
		int n = nums.size();
		for (int i = 1; i <= n; i++)
		{
			int count = hashmap[i];
			if (count == 2)
				res[0] = i;
			else if (count == 0)
				res[1] = i;
		}
		return res;
	}
};

class Solution
{
public:
	vector<int> findErrorNums(vector<int>& nums)
	{
		vector<int> errorNums(2);
		int n = nums.size();
		unordered_map<int, int> mp;
		for (auto& num : nums)
		{
			mp[num]++;
		}
		for (int i = 1; i <= n; i++)
		{
			int count = mp[i];
			if (count == 2)
			{
				errorNums[0] = i;
			}
			else if (count == 0)
			{
				errorNums[1] = i;
			}
		}
		return errorNums;
	}
};
