#include <algorithm>
#include <cctype>
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
#include <unordered_set>
using namespace std;
class Solution
{
public:
    bool valid(string s)
    {
        int n = s.length();
        for (int i = 0; i < n / 2; i++)
        {
            if (s[i] != s[n - i - 1])
                return false;
        }
        return true;
    }
    bool validPalindrome(string s)
    {
        if (valid(s))
            return true;
        int n = s.length();
        for (int i = 0; i < n / 2; i++)
        {
            if (s[i] != s[n - i - 1])
            {
                string s1 = s;
                s1.erase(i, 1);
                string s2 = s;
                s2.erase(n - i - 1, 1);
                return valid(s1) || valid(s2);
                // return valid(s.erase(i, 1)) || valid(s.erase(n - i, 1));
            }
        }
        return true;
    }
};