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
	//这是暴力递归解法
	int coinChange1(vector<int>& coins, int amount)
	{
		if (amount == 0)
			return 0;
		if (amount < 0)
			return -1;
		int res = INT_MAX;
		for (auto & coin : coins)
		{
			int subProblem = coinChange1(coins, amount - coin);
			if (subProblem == -1) continue;
			res = min(res, subProblem + 1);
		}
		return res == INT_MAX ? -1 : res;
	}

	int coinChange(vector<int>& coins, int amount)
	{
		memo = vector<int>(amount + 1, -666);
		return dp(coins, amount);
	}

private:
	vector<int> memo;
	int dp(vector<int>& coins, int amount)
	{
		if (amount == 0) return 0;
		if (amount < 0) return -1;

		if (memo[amount] != -666) return memo[amount];

		int res = INT_MAX;
		for (int coin : coins)
		{
			int subProblem = dp(coins, amount - coin);
			if (subProblem == -1) continue;
			res = min(res, subProblem + 1);
		}
		memo[amount] = res == INT_MAX ? -1 : res;
		return memo[amount];
	}

};