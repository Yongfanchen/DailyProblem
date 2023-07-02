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
	vector<vector<int>> largestLocal(vector<vector<int>>& grid)
	{
		int n = grid.size();
		vector<vector<int>> res;
		for (int i = 1; i < n - 1; i++) {
			vector<int> res1;
			for (int j = 1; j < n - 1; j++) {
				int maxLocal = 0;
				for (int i1 = i - 1; i1 <= i + 1; i1++) {
					for (int j1 = j - 1; j1 <= j + 1; j1++) {
						maxLocal = max(maxLocal, grid[i1][j1]);
					}
				}
				res1.push_back(maxLocal);
			}
			res.push_back(res1);
		}
		return res;
	}
};
//int main()
//{
//	Solution s;
//	vector<vector<int>> res1 = {{1,0,1}, {0,1,0},{1,0,0}};
//	//int  res = s.numSpecial(res1);
//	return 0;
//}