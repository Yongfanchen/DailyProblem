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
    int numJewelsInStones(string jewels, string stones)
    {
        int sum = 0;
        for (auto &stone : stones)
        {
            if (count(jewels.begin(), jewels.end(), stone))
                sum++;
        }
        return sum;
    }
};