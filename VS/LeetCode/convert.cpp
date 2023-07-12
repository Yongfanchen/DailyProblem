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
	string convert(string s, int numRows)
	{
		int n = s.length();
		int r = numRows;


		if (r == 1 || r >= n) {
			return s;
		}

		int t = t * 2 - 2;//计算周期
		int c = (n + t - 1) / t * (r - 1);  //计算多少列
		vector<string> mat(r, string(c, 0));
		//for(int i =0,x=0,y=0;)

	}
};


