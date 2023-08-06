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

		//DP����ĺ�����ʲô��
		//DP[i,j]�ĺ�����
		//DP[i,j]������s1[0..i]��s2[0..j]����С�༭����
		vector<vector<int>> DP(n + 1, vector<int>(m + 1));

		//�߽��ʼ��
		//if(word1[i] == world2[j]) ��ôDP[i][j] = DP[i-1][j-1]
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