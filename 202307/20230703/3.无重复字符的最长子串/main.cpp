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
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int n = s.length();
        int maxN = INT_MIN;
        int left = 0;
        while (left < n)
        {
            for (int i = left; i < n; i++)
            {
                string temp = s.substr(left, i - left);
                // if (temp)
            }
        }
    }
};