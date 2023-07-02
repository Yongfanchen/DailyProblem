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
	bool isEaual(vector<vector<int>>& mat, vector<vector<int>>& target)
	{
		int n = mat.size();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (mat[i][j] != target[i][j]) return false;
			}
		}
		return true;
	}
	vector<vector<int>> Rotation(vector<vector<int>> &mat)
	{
		int n1 = mat.size();
		vector<vector<int>> res(n1, vector<int>(n1));
		int n = mat.size();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				res[j][n - 1 - i] = mat[i][j];
			}
		}
		return res;
	}
	bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target)
	{
		vector<vector<int>> temp = mat;
		for (int i = 0; i < 4; i++) {
			temp = Rotation(temp);
			if (isEaual(temp, target)) {
				return true;  //你要想清楚只需要一个就可以返回true   
			}
		}
		return false;
	}
};
//int main()
//{
//	Solution s;
//	vector<vector<int>> res1 = {{1,0,1}, {0,1,0},{1,0,0}};
//	//int  res = s.numSpecial(res1);
//	return 0;
//}