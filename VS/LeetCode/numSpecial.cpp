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
	int numSpecial(vector<vector<int>>& mat)
	{
		int res = 0;
		int m = mat.size();
		int n = mat[0].size();
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				int temp = mat[i][j];
				if (mat[i][j] == 1) {
					bool isZero = true;
					for (int k = 0; k < n; k++) {
						if (k != j) {
							int temp1 = mat[i][k];
							if (mat[i][k] != 0) {
								isZero = false;
								break;
							}
						}
							
					}
					for (int s = 0; s < m; s++) {
						if (s != i) {
							int temp2 = mat[s][j];
							if (mat[s][j] != 0) {
								isZero = false;
								break;
							}
						}
			
					}
					if (isZero == true) res++;
				}
			}
		}

		return res;
	}
};
//int main()
//{
//	Solution s;
//	vector<vector<int>> res1 = {{1,0,1}, {0,1,0},{1,0,0}};
//	int  res = s.numSpecial(res1);
//	return 0;
//}