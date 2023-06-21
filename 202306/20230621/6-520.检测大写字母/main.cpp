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
    bool isAllUpper(string word)
    {
        for (auto &ch : word)
        {
            if (ch > 'Z' || ch < 'A')
            {
                return false;
            }
        }
        return true;
    }
    bool isAlllower(string word)
    {
        for (auto &ch : word)
        {
            if (ch > 'z' || ch < 'a')
            {
                return false;
            }
        }
        return true;
    }
    bool firstUpper(string word)
    {
        int n = word.size();
        for (int i = 1; i < n; i++)
        {
            if (word[i] > 'z' || word[i] < 'a')
            {
                return false;
            }
        }
        if ('a' <= word[0] <= 'z' || 'A' <= word[0] <= 'Z')
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool detectCapitalUse(string word)
    {
        if (isAlllower(word) || isAllUpper(word) || firstUpper(word))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};