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
	// �� s[i] ���²���һ��
	string minusOne(string s, int j) {
		if (s[j] == '0') s[j] = '9';
		else s[j] -= 1;
		return s;
	}
	int openLock(vector<string>& deadends, string target) {
		//��¼��Ҫ��������������
		unordered_set<string> deads;
		for (auto & s : deadends) {
			deads.insert(s);
		}

		//��¼�Ѿ���ٹ������룬��ֹ�߻�ͷ·
		unordered_set<string> visited;
		queue<string> q;
		//����㿪ʼ���������������
		int step = 0;
		q.push("0000");
		visited.insert("0000");

		while (!q.empty()) {
			int sz = q.size();
			/*����ǰ�����е����нڵ�����Χ��ɢ*/
			for (int i = 0; i < sz; i++) {
				string cur = q.front();
				q.pop();

				/*�ж��Ƿ񵽴��յ�*/
				if (deads.count(cur)) continue;
				if (cur == target) return step;

				/*��ÿһ���ڵ��δ�������ڽڵ�������*/
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
			/*�������Ӳ���*/
			step++;
		}
		//���������˶�û���ҵ�Ŀ�꣬�Ǿ����Ҳ�����
		return -1;
	}

};