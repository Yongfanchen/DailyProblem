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
    int calPoints(vector<string> &operations)
    {
        vector<int> res;
        int n = operations.size();
        for (int i = 0; i < n; i++)
        {
            if (operations[i] != "+" && operations[i] != "D" && operations[i] != "C")
                res.emplace_back(stoi(operations[i]));
            else if (operations[i] == "+")
                res.emplace_back(res[res.size() - 1] + res[res.size() - 2]);
            else if (operations[i] == "D")
                res.emplace_back(res[res.size() - 1] * 2);
            else if (operations[i] == "C")
                res.erase(res.begin() + res.size() - 1);
        }
        // return
        int sum = 0;
        for (auto &num : res)
        {
            sum += num;
        }
        return sum;
    }
};