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
    string convertToBase7(int num)
    {
        if (num == 0)
        {
            return "0";
        }
        string res;
        bool isMinus = false;
        if (num < 0)
        {
            isMinus = true;
            num = -num;
        }
        while (num != 0)
        {
            res += to_string(num % 7);
            num /= 7;
        }
        if (isMinus)
        {
            res += "-";
        }
        reverse(res.begin(), res.end());
        return res;
    }
};