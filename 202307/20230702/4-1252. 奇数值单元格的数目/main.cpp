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
    int oddCells(int m, int n, vector<vector<int>> &indices)
    {
        vector<vector<int>> res(m, vector<int>(n, 0));
        for (auto indice : indices)
        {
            int rowNum = indice[0];
            int lowNum = indice[1];
            for (int i = 0; i < n; i++)
            {
                res[rowNum][i] += 1;
            }
            for (int j = 0; j < m; j++)
            {
                res[j][lowNum] += 1;
            }
        }
        int sum = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (res[i][j] % 2 == 1)
                {
                    sum++;
                }
            }
        }
        return sum;
    }
};