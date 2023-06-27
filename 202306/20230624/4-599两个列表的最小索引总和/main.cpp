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
    vector<string> findRestaurant(vector<string> &list1, vector<string> &list2)
    {
        unordered_map<string, int> index;
        int n1 = list1.size();
        for (int i = 0; i < n1; i++)
        {
            index[list1[i]] = i;
        }
        vector<string> ret;
        int indexSum = INT_MAX;
        int n2 = list2.size();
        for (int i = 0; i < n2; i++)
        {
            if (index.count(list2[i]) > 0)
            {
                int j = index[list2[i]];
                if (i + j < indexSum)
                {
                    ret.clear();
                    ret.push_back(list2[i]);
                    indexSum = j + i;
                }
                else if (i + j == indexSum)
                {
                    ret.push_back(list2[i]);
                }
            }
        }
        return ret;
    }
};