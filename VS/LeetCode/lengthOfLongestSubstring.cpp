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
	int lengthOfLongestSubstring(string s)
	{
		int size = s.length();
		unordered_set<char> temp;
		int maxStr = 0;
		int left = 0;
		for (int i = 0; i < size; i++)
		{
			while (temp.find(s[i]) != temp.end())
			{
				temp.erase(s[left]);
				left++;
			}
			maxStr = max(maxStr, i - left + 1);
			temp.insert(s[i]);
		}
		return maxStr;
	}
};