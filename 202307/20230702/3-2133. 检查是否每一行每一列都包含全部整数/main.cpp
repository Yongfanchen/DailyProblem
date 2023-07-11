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
    bool checkValid(vector<vector<int>> &matrix)
    {

        int n = matrix.size();
        vector<int> temp(n);
        for (int i = 1; i <= n; i++)
        {
            temp.emplace_back(i);
        }
        for (int i = 0; i < n; i++)
        {
            vector<int> temp1 = temp;
            vector<int> temp2 = temp;
            for (int j = 0; j < n; j++)
            {
                auto iter1 = find(temp1.begin(), temp1.end(), matrix[i][j]);
                if (iter1 != temp1.end())
                {
                    // 说明找到了 划掉
                    temp1.erase(iter1);
                }
                else
                {
                    return false;
                }
                auto iter2 = find(temp2.begin(), temp2.end(), matrix[j][i]);
                if (iter2 != temp2.end())
                {
                    // 说明找到了 划掉
                    temp2.erase(iter2);
                }
                else
                {
                    return false;
                }
            }
        }
        // for (int j = 0; j < n; j++) {
        //	vector<int> temp2 = temp;
        //	for (int i = 0; i < n; i++) {
        //		auto iter = find(temp2.begin(), temp2.end(), matrix[i][j]);
        //		if (iter != temp2.end()) {
        //			temp2.erase(iter);
        //		}
        //		else {
        //			return false;
        //		}
        //	}
        // }
        return true;
    }
};