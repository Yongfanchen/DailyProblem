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
		// ö�� a
		for (int first = 0; first < n; ++first) {
			// ��Ҫ����һ��ö�ٵ�������ͬ
			if (first > 0 && nums[first] == nums[first - 1]) {
				continue;
			}
			// c ��Ӧ��ָ���ʼָ����������Ҷ�
			int third = n - 1;
			int target = -nums[first];
			// ö�� b
			for (int second = first + 1; second < n; ++second) {
				// ��Ҫ����һ��ö�ٵ�������ͬ
				if (second > first + 1 && nums[second] == nums[second - 1]) {
					continue;
				}
				// ��Ҫ��֤ b ��ָ���� c ��ָ������
				while (second < third && nums[second] + nums[third] > target) {
					--third;
				}
				// ���ָ���غϣ����� b ����������
				// �Ͳ��������� a+b+c=0 ���� b<c �� c �ˣ������˳�ѭ��
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