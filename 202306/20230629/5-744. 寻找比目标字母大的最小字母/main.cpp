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
    char nextGreatestLetter(vector<char> &letters, char target)
    {
        char res = 'z';
        bool isModyfy = false;
        for (auto &letter : letters)
        {
            if (letter > target)
            {
                isModyfy = true;
                if (letter < res)
                {
                    res = letter;
                }
            }
        }
        if (isModyfy)
            return res;
        else
            return letters[0];
    }
};