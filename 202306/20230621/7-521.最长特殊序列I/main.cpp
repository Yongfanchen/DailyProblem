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
    int findLUSlength(string a, string b)
    {
        return a != b ? max(a.length(), b.length()) : -1;
    }
};