#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
using namespace std;
class Solution {
public:
	string toHex(int num) {

		if (num == 0) {
			return "0";
		}

		string res = "";
		unsigned int n = num;
		while (n > 0) {
			int remainder = n % 16;
			if (remainder < 10) {
				res = char('0' + remainder) + res;
			} else {
				res = char('a' + (remainder - 10)) + res;
			}
			n /= 16;
		}
		return res;
	}
};