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
class Solution1 {
public:
	//这是暴力递归解法
	int coinChange1(vector<int>& coins, int amount) {
		if (amount == 0)
			return 0;
		if (amount < 0)
			return -1;
		int res = INT_MAX;
		for (auto & coin : coins) {
			int subProblem = coinChange1(coins, amount - coin);
			if (subProblem == -1) continue;
			res = min(res, subProblem + 1);
		}
		return res == INT_MAX ? -1 : res;
	}

	int coinChange(vector<int>& coins, int amount) {
		memo = vector<int>(amount + 1, -666);
		return dp(coins, amount);
	}

private:
	vector<int> memo;
	int dp(vector<int>& coins, int amount) {
		if (amount == 0) return 0;
		if (amount < 0) return -1;

		if (memo[amount] != -666) return memo[amount];

		int res = INT_MAX;
		for (int coin : coins) {
			int subProblem = dp(coins, amount - coin);
			if (subProblem == -1) continue;
			res = min(res, subProblem + 1);
		}
		memo[amount] = res == INT_MAX ? -1 : res;
		return memo[amount];
	}

};



//手撕一遍零钱兑换
class Solution12 {
public:
	int coinChange(vector<int>& coins, int amount) {

	}
	int dp(vector<int>& coins, int amount) {
		if (amount == 0) return 0;
		if (amount < 0) return -1;

		int res = INT_MAX;
		for (int coin : coins) {
			int subProblem = dp(coins, amount - coin);
			if (subProblem == -1) continue;
			res = min(res, subProblem + 1);
		}
		return res == INT_MAX ? -1 : res;
	}
};

class Solution {
private:
	vector<int> memo;

	//memo数组记录了 amount对应的最优解，-666表示还未被计算
	int dp(vector<int>&coins, int amount) {
		if (amount == 0) return 0;
		if (amount < 0) return -1;
		if (memo[amount] != -666) return memo[amount];

		int res = INT_MAX;

		for (int coin : coins) {
			int subProblem = dp(coins, amount - coin);
			if (subProblem == -1) continue;
			res = min(res, subProblem + 1);

			memo[amount] = res == INT_MAX ? -1 : res;
			return memo[amount];
		}
	}
};

int coinChange(vector<int>& coins, int amount) {
	//初始化dp数组
	vector<int> dp(amount + 1, amount + 1);
	//dp数组的含义是：当目标金额是i时，至少需要dp[i]枚硬币凑出
	dp[0] = 0;

	for (int i = 0; i < dp.size(); i++) {
		//内层for循环在求所有选择的最小值
		for (int coin : coins) {
			//子问题无解，跳过
			if (i - coin < 0) {
				continue;
			}
			dp[i] = min(dp[i], dp[i - coin] + 1);
		}
	}
	return (dp[amount] == amount + 1) ? -1 : dp[amount];
}


//需要你从0写出来  你要自己完整完全的自己写出来
class MyCoin {
public:
	vector<int> memo;
	int coinChange(vector<int>& coins, int amount) {

	}
	int dp(vector<int>&coins, int amount) {
		if (amount == 0) return 0;
		if (amount < 0) return -1;
		if (memo[amount] != -666) {
			return memo[amount];
		}

		int res = INT_MAX;
		for (int coin : coins) {
			int subProblem = dp(coins, amount - coin);
			if (subProblem == -1) continue;
			res = min(res, subProblem + 1);
		}
		memo[amount] = (res == INT_MAX) ? -1 : res;
		return memo[amount];
	}

};