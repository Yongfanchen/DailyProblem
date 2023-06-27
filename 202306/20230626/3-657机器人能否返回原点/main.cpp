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
    // L R U D
    bool judgeCircle(string moves)
    {
        unordered_map<char, int> hashmap;
        for (auto &move : moves)
            hashmap[move]++;
        return hashmap['L'] == hashmap['R'] && hashmap['U'] == hashmap['D'];
    }
};