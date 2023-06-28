#include <algorithm>
#include <cctype>
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
// class Solution
// {
// public:
// 	int maxIndexofRange(vector<int> &nums, int k)
// 	{
// 		int n = nums.size();
// 		bool haveStart = false;
// 		int maxIndex = 0;
// 		int start = 0;
// 		for (int i = 0; i < n; i++)
// 		{
// 			if (nums[i] == k)
// 				if (haveStart == false)
// 					start = i;
// 			if (nums[i] == k)
// 				if (haveStart == true)
// 					maxIndex = max(maxIndex, i);
// 		}
// 		return maxIndex - start + 1;
// 	}
// 	int findShortestSubArray(vector<int> &nums)
// 	{
// 		int n = nums.size();
// 		vector<int> res;
// 		unordered_map<int, int> hashmap;
// 		for (auto &num : nums)
// 			hashmap[num]++;
// 		int maxCount = 0, maxValueofMax = 0;
// 		for (const auto &pair : hashmap)
// 		{
// 			int key = pair.first;
// 			int value = pair.second;
// 			if (value > maxCount)
// 			{
// 				res.clear();
// 				maxValueofMax = value;
// 				res.emplace_back(maxValueofMax);
// 			}
// 			if (value == maxCount)
// 				res.emplace_back(maxValueofMax);
// 		}
// 		int minRange = INT_MAX;
// 		for (int i = 0; i < res.size(); i++)
// 			minRange = min(minRange, maxIndexofRange(nums, res[i]));
// 		return minRange;
// 	}
// };
// class Solution
// {
// public:
// 	int findShortestSubArray(vector<int> &nums)
// 	{
// 		unordered_map<int, vector<int>> mp;
// 		int n = nums.size();
// 		for (int i = 0; i < n; i++)
// 		{
// 			if (mp.count(nums[i]))
// 			{
// 				mp[nums[i]][0]++;
// 				mp[nums[i]][2] = i;
// 			}
// 			else
// 			{
// 				mp[nums[i]] = {1, i, i};
// 			}
// 		}
// 		int maxNum = 0, minLen = 0;
// 		for (auto &[_, vec] : mp)
// 		{
// 			if (maxNum < vec[0])
// 			{
// 				maxNum = vec[0];
// 				minLen = vec[2] - vec[1] + 1;
// 			}
// 			else if (maxNum == vec[0])
// 			{
// 				if (minLen > vec[2] - vec[1] + 1)
// 				{
// 					minLen = vec[2] - vec[1] + 1;
// 				}
// 			}
// 		}
// 		return minLen;
// 	}
// };
class Solution
{
public:
	int findShortestSubArray(std::vector<int> &nums)
	{
		std::unordered_map<int, std::vector<int>> mp;
		int n = nums.size();
		for (int i = 0; i < n; i++)
		{
			if (mp.count(nums[i]))
			{
				mp[nums[i]][0]++;
				mp[nums[i]][2] = i;
			}
			else
			{
				mp[nums[i]] = std::vector<int>{1, i, i};
			}
		}
		int maxNum = 0, minLen = 0;
		for (auto &pair : mp)
		{
			int key = pair.first;
			std::vector<int> &vec = pair.second;
			if (maxNum < vec[0])
			{
				maxNum = vec[0];
				minLen = vec[2] - vec[1] + 1;
			}
			else if (maxNum == vec[0])
			{
				if (minLen > vec[2] - vec[1] + 1)
				{
					minLen = vec[2] - vec[1] + 1;
				}
			}
		}
		return minLen;
	}
};

// int main()
// {
// 	Solution s;
// 	vector<int> nums = {1, 2, 2, 1, 2, 1, 1, 1, 1, 2, 2, 2};
// 	int res = s.findShortestSubArray(nums);
// 	cout << res << endl;
// 	return 0;
// }