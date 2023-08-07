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
	//操作word1变成word2
	//只操作word1 不操作word2
	//二维数组 dp[i,j] 表示word1[0,i] 到word2[0,j]的最小次数 
	int minDistance(string word1, string word2)
	{
		int m = word1.length();
		int n = word2.length();
		
		vector<vector<int>> dp(m+1, vector<int>(n+1));
		//矩阵声明时的行列式， m是row数 n是colum数
		//所以m是管每一行的第一个
		//所以n是管每一列的第一个
		for (int i = 1; i <= m; i++) {
			dp[i][0] = i;
		}

		for (int i = 1; i <= n; i++) {
			dp[0][i] = i;
		}
		//自底向上求解
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++) {
				if (word1[i - 1] == word2[j - 1]) {
					dp[i][j] = dp[i - 1][j - 1];
				} else {
					dp[i][j] = min(dp[i - 1][j] + 1, min(dp[i][j - 1] + 1, dp[i - 1][j - 1] + 1));
				}
			}
		}
		//存储着整个s1和s2的最小编辑距离
		return dp[m][n];
	}
};