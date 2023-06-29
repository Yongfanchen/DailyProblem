#include <algorithm>
#include <cctype>
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution {
	void dfs(vector<vector<int>> &image, int sr, int sc, int newColor, int oldColor)
	{
		if (sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size() || image[sr][sc] != oldColor)
			return;
	}
	vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
	{

	}
};