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
	vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter)
	{
		vector <vector<int>> res;
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				res.push_back({i,j});
			}
		}
		sort(res.begin(), res.end(), [=](vector<int> &a, vector<int> &b) {
			return abs(a[0] - rCenter) + abs(a[1] - cCenter) < abs(b[0] - rCenter) + abs(b[1] - cCenter);
		});
		return res;
	}
};
//int main()
//{
//	//Solution s;
//	//vector<vector<int>> res1 = {{4,3,2,-1}, {3,2,1,-1},{1,1,-1,-2},{1,1,-1,-2}};
//	//int  res = s.countNegatives(res1);
//	//return 0;
//}