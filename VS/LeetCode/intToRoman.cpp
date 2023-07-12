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
using namespace std;

class Solution {
public:
	const vector<pair <int, string>> valueAndstring = {
	{1000,"M"},
	{900,"CM"},
	{500,"D"},
	{400,"CD"},
	{100,"C"},
	{90,"XC"},
	{50,"L"},
	{40,"XL"},
	{10,"X"},
	{9,"IX"},
	{5,"V"},
	{4,"IV"},
	{1,"I"},
	};
	string intToRoman(int num)
	{
		string res;
		for (auto & iterator : valueAndstring) {
			int value = iterator.first;
			string str = iterator.second;
			while (num >= value) {
				num -= value;
				res += str;
			}
			if (num == 0) {
				break;
			}
		}
		return res;
	}
};