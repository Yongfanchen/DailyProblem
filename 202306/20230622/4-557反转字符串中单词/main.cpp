#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <stack>
#include <cctype>
using namespace std;
template <typename ValueType>
void printVector(const std::vector<ValueType> &vec)
{
    std::cout << "{";
    for (size_t i = 0; i < vec.size(); ++i)
    {
        if (i > 0)
        {
            std::cout << ", ";
        }
        std::cout << vec[i];
    }
    std::cout << "}" << std::endl;
}

class Solution
{
public:
    vector<string> spiltStr(const string &s, char c)
    {
        vector<string> res;
        string current;
        for (char ch : s)
        {
            if (ch == c)
            {
                res.push_back(current);
                current.clear();
            }
            else
            {
                current += ch;
            }
        }
        res.push_back(current);
        return res;
    }
    string reverseWords(string s)
    {
        string res;
        vector<string> spilts = spiltStr(s, ' ');
        // int n = spilts.size
        int i = 0;
        for (auto str : spilts)
        {
            reverse(str.begin(), str.end());
            res += str;
            res += " ";
        }
        res.erase(res.length() - 1, 1);
        return res;
    }
};

int main()
{
    Solution s;
    string str = "Let's take LeetCode contest";
    vector<string> splitstr = s.spiltStr(str, ' ');
    printVector(splitstr);
    string res = s.reverseWords(str);
    std::cout << res << endl;
    return 0;
}