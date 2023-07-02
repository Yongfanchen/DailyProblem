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
	int countNegatives(vector<vector<int>>& grid)
	{
		int sum = 0;
		int m = grid.size();
		int n = grid[0].size();
		for (size_t i = 0; i < m; i++) {
			for (size_t j = 0; j < n; j++) {
				int temp = grid[i][j];
				if (grid[i][j] < 0) {
					sum += n - j;
					break;
				}

			}
		}
		return sum;
	}
};
//int main()
//{
//	Solution s;
//	vector<vector<int>> res1 = {{4,3,2,-1}, {3,2,1,-1},{1,1,-1,-2},{1,1,-1,-2}};
//	int  res = s.countNegatives(res1);
//	return 0;
//}