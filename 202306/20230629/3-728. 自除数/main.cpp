#include <algorithm>
#include <cctype>
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
public:
	bool isDividingNum(int n)
	{
		vector<int> res;
		while (n > 0) {
			int temp = n % 10;
			if (temp != 0)
				res.emplace_back(temp);
			n = n / 10;
		}
		for (int i = 0; i < res.size(); i++) {
			if (n % res[i] != 0)
				return false;
		}
		return true;
	}
	vector<int> selfDividingNumbers(int left, int right)
	{
		vector<int> res;
		for (int i = left; i <= right; i++) {
			if (isDividingNum(i))
				res.emplace_back(i);
		}
		return res;
	}
};