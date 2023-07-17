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
class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> res;
		int n = nums.size();
		if (n < 3) {
			return res;
		}
		if (n == 3) {
			if (nums[0] + nums[1] + nums[2] == 0) {
				return {{nums[0],nums[1],nums[2]}};
			}
			else {
				return res;
			}
		}
	}
};

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		int n = nums.size();
		sort(nums.begin(), nums.end());
		vector<vector<int>> ans;
		// 枚举 a
		for (int first = 0; first < n; ++first) {
			// 需要和上一次枚举的数不相同
			if (first > 0 && nums[first] == nums[first - 1]) {
				continue;
			}
			// c 对应的指针初始指向数组的最右端
			int third = n - 1;
			int target = -nums[first];
			// 枚举 b
			for (int second = first + 1; second < n; ++second) {
				// 需要和上一次枚举的数不相同
				if (second > first + 1 && nums[second] == nums[second - 1]) {
					continue;
				}
				// 需要保证 b 的指针在 c 的指针的左侧
				while (second < third && nums[second] + nums[third] > target) {
					--third;
				}
				// 如果指针重合，随着 b 后续的增加
				// 就不会有满足 a+b+c=0 并且 b<c 的 c 了，可以退出循环
				if (second == third) {
					break;
				}
				if (nums[second] + nums[third] == target) {
					ans.push_back({nums[first], nums[second], nums[third]});
				}
			}
		}
		return ans;
	}
};
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
using namespace std;
class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		int n = nums.size();
		sort(nums.begin(), nums.end());
		vector<vector<int>> ans;
		for (int first = 0; first < n; first++) {
			if (first > 0 && nums[first] == nums[first - 1]) continue;
			int third = n - 1;
			int target = 0 - nums[first];
			for (int second = first + 1; second < n; ++second) {
				if (second > first + 1 && nums[second] == nums[second - 1]) continue;
				while (second<third &&nums[second] + nums[third]>target) --third;
				if (second == third) 	break;
				if (nums[second] + nums[third] == target) ans.push_back({nums[first], nums[second], nums[third]});
			}
		}
		return ans;
	}
};

vector<vector<int>> threeSum(vector<int>& nums) {
	vector<vector<int>> ans;
	int n = nums.size();
	sort(nums.begin(), nums.end());
	for (int  first = 0; first < n; first++) {
		if (first > 0 && nums[first] == nums[first - 1]) continue;
		int third = n - 1;
		int target = -nums[first];
		for (int  second = first+1; second < n; second++) {
			if (second > first + 1 && nums[second] == nums[second - 1]) continue;
			while (second<third&&nums[second] + nums[third]>target) --third;
			if (second == third) break;
			if (nums[second] + nums[third] == target) ans.push_back({nums[first],nums[second],nums[third]});
		}
	}
	return ans;
}