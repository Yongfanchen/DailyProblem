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
	vector<vector<int>> transpose(vector<vector<int>>& matrix)
	{
		int m = matrix.size();
		int n = matrix[0].size();
		vector<vector<int>> res(n, vector<int>(m));
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				res[j][i] = matrix[i][j];
			}
		}
		return res;
	}
};
//int main()
//{
//	Solution s;
//	//vector<vector<int>> res = s.transpose
//}