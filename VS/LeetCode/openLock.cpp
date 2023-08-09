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
#include <queue>
using namespace std;
class Solution {
public:
	string plusOne(string s, int j) {
		if (s[j] == '9') s[j] = '0';
		else s[j] += 1;
		return s;
	}
	// 将 s[i] 向下拨动一次
	string minusOne(string s, int j) {
		if (s[j] == '0') s[j] = '9';
		else s[j] -= 1;
		return s;
	}
	int openLock(vector<string>& deadends, string target) {
		//记录需要跳过的死亡密码
		unordered_set<string> deads;
		for (auto & s : deadends) {
			deads.insert(s);
		}

		//记录已经穷举过的密码，防止走回头路
		unordered_set<string> visited;
		queue<string> q;
		//从起点开始启动广度优先搜索
		int step = 0;
		q.push("0000");
		visited.insert("0000");

		while (!q.empty()) {
			int sz = q.size();
			/*将当前队列中的所有节点向周围扩散*/
			for (int i = 0; i < sz; i++) {
				string cur = q.front();
				q.pop();

				/*判断是否到达终点*/
				if (deads.count(cur)) continue;
				if (cur == target) return step;

				/*将每一个节点的未遍历相邻节点加入队列*/
				for (int j = 0; j < 4; j++) {
					string up = plusOne(cur, j);
					if (!visited.count(up)) {
						q.push(up);
						visited.insert(up);
					}
					string down = minusOne(cur, j);
					if (!visited.count(down)) {
						q.push(down);
						visited.insert(down);
					}
				}
			}
			/*这里增加步数*/
			step++;
		}
		//如果穷举玩了都没有找到目标，那就是找不到了
		return -1;
	}

};