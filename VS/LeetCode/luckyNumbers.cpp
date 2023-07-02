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
	vector<int> luckyNumbers(vector<vector<int>>& matrix)
	{
		vector<int> res;
		int m = matrix.size();
		int n = matrix[0].size();
		for (size_t i = 0; i < m; i++) {
			int min = INT_MAX;
			int clow;
			for (size_t j = 0; j < n; j++) {
				int temp = matrix[i][j];
				if (matrix[i][j] < min) {
					min = matrix[i][j];
					clow = j;
				}
			}
			int max = INT_MIN;
			for (size_t j = 0; j < m; j++) {
				int temp = matrix[j][clow];
				if (matrix[j][clow] > max) {
					max = matrix[j][clow];
				}
			}
			if (max == min)
				res.emplace_back(max);
		}
		return res;
	}
};
//int main()
//{
//	Solution s;
//	vector<vector<int>> res1 = {{3,7,8}, {9,11,13},{15,16,17}};
//	vector<int > res = s.luckyNumbers(res1);
//	return 0;
//}