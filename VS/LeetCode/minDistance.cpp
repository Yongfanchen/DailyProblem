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
	//����word1���word2
	//ֻ����word1 ������word2
	//��ά���� dp[i,j] ��ʾword1[0,i] ��word2[0,j]����С���� 
	int minDistance(string word1, string word2)
	{
		int m = word1.length();
		int n = word2.length();
		
		vector<vector<int>> dp(m+1, vector<int>(n+1));
		//��������ʱ������ʽ�� m��row�� n��colum��
		//����m�ǹ�ÿһ�еĵ�һ��
		//����n�ǹ�ÿһ�еĵ�һ��
		for (int i = 1; i <= m; i++) {
			dp[i][0] = i;
		}

		for (int i = 1; i <= n; i++) {
			dp[0][i] = i;
		}
		//�Ե��������
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++) {
				if (word1[i - 1] == word2[j - 1]) {
					dp[i][j] = dp[i - 1][j - 1];
				} else {
					dp[i][j] = min(dp[i - 1][j] + 1, min(dp[i][j - 1] + 1, dp[i - 1][j - 1] + 1));
				}
			}
		}
		//�洢������s1��s2����С�༭����
		return dp[m][n];
	}
};