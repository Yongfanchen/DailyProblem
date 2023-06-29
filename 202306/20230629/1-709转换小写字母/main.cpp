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
    string toLowerCase(string s)
    {
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            if ('A' <= s[i] <= 'Z')
            {
                // s[i] = tolower(s[i]);
                s[i] = s[i] + 32;
            }
        }
        return s;
    }
};