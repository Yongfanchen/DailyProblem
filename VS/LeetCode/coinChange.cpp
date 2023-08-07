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
	//���Ǳ����ݹ�ⷨ
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



//��˺һ����Ǯ�һ�
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

	//memo�����¼�� amount��Ӧ�����Ž⣬-666��ʾ��δ������
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
	//��ʼ��dp����
	vector<int> dp(amount + 1, amount + 1);
	//dp����ĺ����ǣ���Ŀ������iʱ��������Ҫdp[i]öӲ�Ҵճ�
	dp[0] = 0;

	for (int i = 0; i < dp.size(); i++) {
		//�ڲ�forѭ����������ѡ�����Сֵ
		for (int coin : coins) {
			//�������޽⣬����
			if (i - coin < 0) {
				continue;
			}
			dp[i] = min(dp[i], dp[i - coin] + 1);
		}
	}
	return (dp[amount] == amount + 1) ? -1 : dp[amount];
}


//��Ҫ���0д����  ��Ҫ�Լ�������ȫ���Լ�д����
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