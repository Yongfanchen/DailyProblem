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
	int maxArea(vector<int>& height)
	{
		int l = 0, r = height.size() - 1;
		int res = 0;
		while (l < r) {
			res = max(min(height[r], height[l]) *(r - l + 1), res);
			if (height[l] <= height[r]) {
				++l;
			}
			else {
				--r;
			}
		}
		return res;
	}
};