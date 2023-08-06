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
class Solution
{
public:
	int minDistance(string word1, string word2)
	{
		int n = word1.length();
		int m = word2.length();


		if (n*m == 0) return n + m;

		//DP数组的含义是什么？
		//DP[i,j]的含义是
		//DP[i,j]返回是s1[0..i]和s2[0..j]的最小编辑距离
		vector<vector<int>> DP(n + 1, vector<int>(m + 1));

		//边界初始化
		//if(word1[i] == world2[j]) 那么DP[i][j] = DP[i-1][j-1]
		//else DP[i][j] = 1 + min(DP[i][j-1], DP[i-1][j], DP[i-1][j-1])
		for (int i = 0; i < n + 1; i++)
			DP[i][0] = i;

		for (int j = 0; j < m + 1; j++)
			DP[0][j] = j;

		for (int i = 1; i < n+1; i++)
		{
			for (int j = 1; j < m + 1; j++)
			{
				int left = DP[i - 1][j] + 1;
			}
		}



	}
};