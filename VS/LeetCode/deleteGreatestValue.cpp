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
//#include 
using namespace std;
class Solution {
public:
	int deleteGreatestValue(vector<vector<int>>& grid)
	{
		int m = grid.size(), n = grid[0].size();
		vector< multiset<int> >st(m);
		for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) st[i].insert(grid[i][j]);

		int ans = 0;
		for (int k = 1; k <= n; k++) {
			int mx = 0;
			for (int i = 0; i < m; i++) {
				mx = max(mx, *prev(st[i].end()));
				st[i].erase(prev(st[i].end()));
			}
			ans += mx;
		}
		return ans;
	}
};