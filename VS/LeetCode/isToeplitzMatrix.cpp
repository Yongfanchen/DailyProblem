#include <algorithm>
#include <cctype>
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
public:
	bool isToeplitzMatrix(vector<vector<int>> &matrix)
	{
		int m = matrix.size(), n = matrix[0].size();
		int val = 0;
		if (m == 1 || n == 1) return true;
		for (int i = 0; i < n; i++) {
			val = matrix[0][i];
			for (int j = 0; j < m && i + j < n; j++) {
				if (matrix[j][i + j] != val) return false;
			}
		}
		for (int i = 1; i < m; i++) {
			val = matrix[i][0];
			for (int j = 1; i + j < m && j < n; j++) {
				if (matrix[i + j][j] != val) return false;
			}
		}
		return true;
	}
};
class Solution1 {
public:
	bool isToeplitzMatrix(vector<vector<int>>& matrix)
	{
		int m = matrix.size(), n = matrix[0].size();
		for (int i = 1; i < m; i++) {
			for (int j = 1; j < n; j++) {
				if (matrix[i][j] != matrix[i - 1][j - 1]) {
					return false;
				}
			}
		}
		return true;
	}
};

