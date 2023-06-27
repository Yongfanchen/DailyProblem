#include <algorithm>
#include <cctype>
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
#include <unordered_set>
using namespace std;
class Solution
{
public:
	vector<vector<int>> imageSmoother(vector<vector<int>> &img)
	{
		// vector<vector<int>> res;
		int m = img.size();
		int n = img[0].size();
		vector<vector<int>> res(m, vector<int>(n));
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				int num = 0;
				int sum = 0;
				for (int x = i - 1; x <= i + 1; x++)
				{
					for (int y = j - 1; y <= j + 1; y++)
					{
						if (x >= 0 && x < m && y >= 0 && y < n)
						{
							num++;
							sum += img[x][y];
						}
					}
				}
				res[i][j] = sum / num;
			}

		}
		return res;
	}
};
//±ê×¼´ð°¸
class Solution
{
public:
	vector<vector<int>> imageSmoother(vector<vector<int>>& img)
	{
		int m = img.size(), n = img[0].size();
		vector<vector<int>> ret(m, vector<int>(n));
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				int num = 0, sum = 0;
				for (int x = i - 1; x <= i + 1; x++)
				{
					for (int y = j - 1; y <= j + 1; y++)
					{
						if (x >= 0 && x < m && y >= 0 && y < n)
						{
							num++;
							sum += img[x][y];
						}
					}
				}
				ret[i][j] = sum / num;
			}
		}
		return ret;
	}
};

