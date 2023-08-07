#include <algorithm>
#include <cctype>
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <set>
#include <array>
#include <cmath>
#include <map>
using namespace std;
class Solution1 {

	//给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。
private:

	vector<vector<int>> res;

	void backtrack(vector<int>& nums, vector<int>&track, vector<bool>& used) {
		//触发调剂
		if (track.size() == nums.size()) {
			res.push_back(track);
			return;
		}
		for (int i = 0; i < nums.size(); i++) {
			//排除不合法的选择
			if (used[i]) {
				continue;
			}
			track.push_back(nums[i]);
			used[i] = true;
			//进入下一层决策树
			backtrack(nums, track, used);
			//取消选择
			track.pop_back();
			used[i] = false;
		}
	}


public:

	//输入一组不重复的数字，返回他们的全排列
	vector<vector<int>> permute(vector<int>& nums) {

		//记录“路径”
		vector<int> track;

		//"路径"中的元素会被标记为true，避免重复使用
		vector<bool> used(nums.size(), false);

		backtrack(nums, track, used);
		return res;
	}
};
//手撕一下全排列
class Solution {
private:

	//这个储存结果
	vector<vector<int>> res;

public:
	vector<vector<int>> permute(vector<int>& nums) {

		//这个是否用过要标记的是数组的数组下标
		vector<bool> used(nums.size(), false);
		vector<int> track;
		backtrack(nums, track, used);
		return res;
	}
	void backtrack(vector<int>& nums, vector<int>&track, vector<bool> &used) {
		
		//触发条件
		if (track.size() == nums.size()) {
			res.push_back(track);
			return;
		}

		for (int i = 0; i < nums.size(); i++) {
			if (used[i]) {
				continue;
			}
			track.push_back(nums[i]);
			//请明确used[i]的代码
			used[i] = true;
			backtrack(nums, track, used);
			track.pop_back();

			used[i] = false;
		}
	}

};