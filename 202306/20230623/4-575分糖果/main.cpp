#include <algorithm>
#include <cctype>
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
#include <unordered_set>
using namespace std;
// bool valueComparetor(const pair<int, int> &a, const pair<int, int> &b)
// {
//     return a.second < b.second;
// }
class Solution
{
public:
    int distributeCandies(vector<int> &candyType)
    {
        unordered_set<int> res;
        for (auto &num : candyType)
        {
            res.emplace(num);
        }
        int n = candyType.size();
        int m = res.size();
        int maxEat = n / 2;
        return maxEat > m ? m : maxEat;
    }
};
int main()
{
}