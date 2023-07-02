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
    bool checkXMatrix(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        if (m != n)
            return false;

        for (size_t i = 0; i < n; i++)
        {
            for (size_t j = 0; j < n; j++)
            {
                // if(i+j==n && grid[i][j]==0)
                if (i == j)
                {
                    if (grid[i][j] != 0)
                        return false;
                }
                if (i + j == n - 1)
                {
                    if (grid[i][j] != 0)
                        return false;
                }
            }
        }
        return true;
    }
};