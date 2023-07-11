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
	vector<int> findColumnWidth(vector<vector<int>>& grid)
	{
		int m = grid.size(), n = grid[0].size();
		vector<int> res;
		for (int j = 0; j < n; j++) {
			int absMax = 0;
			for (int i = 0; i < m; i++) {
				int length = to_string(grid[i][j]).size();
				absMax = max(length,absMax);
			}
			res.emplace_back(absMax);
		}
		return res;
	}
};

//int main()
//{
//	Solution s;
//	vector<vector<int>> grid = {{-15,}};
//	//vector<int> res = s.findColumnWidth();
//}