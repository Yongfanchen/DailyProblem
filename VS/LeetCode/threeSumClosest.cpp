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
	int threeSumClosest(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end());
		int n = nums.size();
		int best = 1e7;
		auto update = [&](int cur) {
			if (abs(cur - target) < abs(best - target)) {
				best = cur;
			}
		};
		for (int first = 0; first < n; first++) {
			if (first > 0 && nums[first] == nums[first - 1]) {
				continue;
			}
			int second = first + 1, third = n - 1;
			while (second < third) {
				int sum = nums[first] + nums[second] + nums[third];
				if (sum == target) {
					return target;
				}
				update(sum);
				if (sum > target) {
					int third1 = third - 1;
					while (second < third1 && nums[third1] == nums[third]) {
						--third1;
					}
					third = third1;
				} else {
					int second1 = second + 1;
					while (second1 < third && nums[second1] == nums[second]) {
						++second1;
					}
					second = second1;
				}
			}
		}
		return best;
	}
};
//int main() {
//	Solution s;
//
//	vector<int> nums= {1,1,1,1};
//	int res = s.threeSumClosest(nums, 4);
//	return 0;
//}