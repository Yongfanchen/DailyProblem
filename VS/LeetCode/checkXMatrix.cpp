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
	bool checkXMatrix(vector<vector<int>> &grid)
	{
		int n = grid.size();
		int m = grid[0].size();
		if (m != n)
			return false;
		for (size_t i = 0; i < n; i++) {
			for (size_t j = 0; j < n; j++) {
				int temp = grid[i][j];
				if (i == j) {
					int temp = grid[i][j];
					if (grid[i][j] == 0)
						return false;
				}
				else if (i + j == n - 1) {
					int temp = grid[i][j];
					if (grid[i][j] == 0)
						return false;
				}
				else {
					int temp = grid[i][j];
					if (grid[i][j] != 0)
						return false;
				}
			}
		}
		return true;
	}
};

//int main()
//{
//	Solution s;
//	vector<vector<int>> matrix = {{2,0,0,1},{0,3,1,0},{0,5,2,0},{4,0,0,2}};
//	vector<vector<int>> matrix1 = {{5,0,0,1},{0,4,1,5},{0,5,2,0},{4,1,0,2}};
//	bool res = s.checkXMatrix(matrix1);
//	return 0;
//}