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
	vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image)
	{
		int m = image.size(), n = image[0].size();
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n / 2; j++) {
				swap(image[i][j], image[i][n - j - 1]);
			}
		}
		vector<vector<int>> temp = image;
		//return image;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (image[i][j] == 1) {
					image[i][j] = 0;
				}
				else {
					image[i][j] = 1;
				}
			}
		}
		return image;
	}
};

//int main()
//{
//	vector<vector<int>> st = {{1,1,0},{1,0,1},{0,0,0}};
//	Solution s;
//	vector<vector<int>> res = s.flipAndInvertImage(st);
//	return 0;
//}