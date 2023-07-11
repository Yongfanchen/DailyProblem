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
#include <cmath>
#include <map>
using namespace std;
class Solution
{
public:
    vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
    {
        vector<int> res;
        int m = mat.size();
        int n = mat[0].size();
        vector<pair<int, int>> hash;
        for (int i = 0; i < m; i++)
        {
            int countSholder = 0;
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] == 1)
                {
                    countSholder++;
                }
            }
            hash.emplace_back(make_pair(i, countSholder));
        }
        sort(hash.begin(), hash.end(), [&](const auto &a, const auto &b)
             {
			if (a.second == b.second) {
				return a.first < b.first;
			}
			return a.second < b.second; });
        for (int i = 0; i < k; i++)
        {
            res.push_back(hash[i].first);
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> res1 = {{1, 1, 0, 0, 0}, {1, 1, 1, 1, 0}, {1, 0, 0, 0, 0}, {1, 1, 0, 0, 0}, {1, 1, 1, 1, 1}};
    vector<int> res = s.kWeakestRows(res1, 3);
    // int  res = s.numSpecial(res1);
    return 0;
}