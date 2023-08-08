#include <algorithm>
#include <cctype>
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
#include <queue>
#include <unordered_set>
#include <algorithm>
using namespace std;
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int n = prices.size();
		vector<vector<int>> dp(n, vector<int>(2));
		dp[0][0] = 0;
		dp[0][1] = -INT_MAX;

		for (int i = 1; i < n; i++) {
			dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
			dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
		}
		return dp[n - 1][0];
	}
};

int maxProfit(vector<int>& prices) {
	int n = prices.size();
	vector<vector<int>> dp(n, vector<int>(2));

	dp[0][0] = 0;
	// Initialize the buy state with the first day's price
	//dp[0][1] = INT_MIN;   这是不对的
	dp[0][1] = -prices[0];
	for (int i = 1; i < n; i++) {
		dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
		dp[i][1] = max(dp[i - 1][1], -prices[i]);
	}
	return dp[n-1][0];
}