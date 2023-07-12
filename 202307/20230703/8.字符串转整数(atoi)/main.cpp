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
    int myAtoi(string s)
    {
        int res = 0;
        int i = 0;
        int flag = 1;
        while (s[i] == ' ')
            i++;
        if (s[i] == '-')
            flag = -1;
        if (s[i] == '+' || s[i] == '-')
            i++;
        while (i < s.length() && isdigit(s[i]))
        {
            int r = s[i] - '0';
            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && r > 7))
            {
                return flag > 0 ? INT_MAX : INT_MIN;
            }
            res = res * 10 + r;
            i++;
        }
        return flag > 0 ? res : -res;
    }
};