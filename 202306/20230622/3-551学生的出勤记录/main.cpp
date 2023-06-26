#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <stack>
#include <cctype>
using namespace std;
class Solution
{
public:
    bool checkRecord(string s)
    {
        int count = 0;
        int n = s.length();
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'A')
            {
                count++;
            }
            if (s[i] == 'L')
            {
                if (s[i + 1] == 'L' && s[i + 2] == 'L')
                {
                    return false;
                }
            }
        }
        if (count >= 2)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
};