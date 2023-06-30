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
	string getBitsFromInt(int n)
	{
		string res;
		while (n > 0) {
			if (n % 2 == 1)
				res += "1";
			else
				res += "0";
			n = n / 2;
		}
		return res;
	}
	bool isPrime(int n)
	{
		if (n == 1)
			return false;
		if (n == 2)
			return true;
		for (int i = 2; i <= n - 1; i++) {
			if (n%i == 0)
				return false;
		}
		return true;
	}
	int countPrimeSetBits(int left, int right)
	{
		int sum = 0;
		for (int i = left; i <= right; i++) {
			string temp;
			temp = getBitsFromInt(i);
			if (isPrime(count(temp.begin(), temp.end(), '1')))
				sum++;
		}
		return sum;
	}
};

int main()
{
	Solution s;
	int count = s.countPrimeSetBits(6, 10);
	int i = 0;
	return 0;
}