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
	string minWindow(string s, string t) {
		unordered_map<char, int> need, window;
		for (char c : t) need[c]++;

		int left = 0, right = 0;
		int vaild = 0;
		//��¼��С�����Ӵ�����ʼ����������
		int start = 0, len = INT_MAX;
		while (right < s.size()) {
			//c�ǽ����봰�ڵ��ַ�
			char c = s[right];
			//���󴰿�
			right++;
			//���д������ݵ�һϵ�и���
			if (need.count(c)) {
				window[c]++;
				if (window[c] == need[c]) {
					vaild++;
				}
			}

			//�ж���ര���Ƿ�Ҫ����
			while (vaild == need.size()) {
				//�����������С�����Ӵ�
				if (right - left < len) {
					start = left;
					len = right - left;
				}
				//d�ǽ��Ƴ����ڵ��ַ�
				char d = s[left];
				//��С����
				left++;
				//���д��������ݵ�һϵ�и���
				if (need.count(d)) {
					if (window[d] == need[d]) {
						vaild--;
					}
					window[d]--;
				}
			}
		}
		//������С�����Ӵ�
		return len == INT_MAX ? "" : s.substr(start, len);
	}
};

int main() {
	Solution s;

	string res = s.minWindow("ADOBECODEBANC", "ABC");
	cout << "res = " << res << endl;
	return 0;
}