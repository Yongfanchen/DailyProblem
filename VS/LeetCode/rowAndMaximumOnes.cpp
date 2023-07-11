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
	vector<int> rowAndMaximumOnes(vector<vector<int>>& mat)
	{
		int m = mat.size(), n = mat[0].size();
		int max = 0;
		int index = 0;
		for (int i = 0; i < m; i++) {
			int sum = 0;
			for (int j = 0; j < n; j++) {
				int temp = mat[i][j];
				if (mat[i][j] == 1) {
					sum++;
				}
			}
			if (sum > max) {
				max = sum;
				index = i;
			}
		}
		return{index,max};
	}
};

//int main()
//{
//	Solution s;
//	vector<vector<int>> temp = {{0,1},{1,0}};
//	vector<int> res = s.rowAndMaximumOnes(temp);
//	return 0;
//}