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
	int diagonalSum(vector<vector<int>>& mat)
	{
		int m = mat.size();
		int sum = 0;
		//int n = mat[0].size();
		for (size_t i = 0; i < m; i++) {
			for (size_t j = 0; j < m; j++) {
				if (i == j || j + i == m - 1)
					sum += mat[i][j];
			}
		}
		return sum;
		if (m % 2 == 0)
			return sum;
		else
			return sum - mat[m / 2][m / 2];
	}
};
//int main()
//{
//	Solution s;
//	vector<vector<int>> res1 = {{1,2,3}, {4,5,6},{7,8,9}};
//	int  res = s.diagonalSum(res1);
//	return 0;
//}