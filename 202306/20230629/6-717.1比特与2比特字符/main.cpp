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
    bool isOneBitCharacter(vector<int> &bits)
    {
        int n = bits.size(), i = 0;
        while (i < n - 1)
        {
            i += bits[i] + 1;
        }
        return i == n - 1;
    }
};