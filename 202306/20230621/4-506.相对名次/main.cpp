#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <stack>
#include <cctype>
using namespace std;
//重点
template <typename T>
void printPairs(const std::vector<std::pair<T, T>> &pairs)
{
    std::cout << "{";
    bool isFirst = true;
    for (const auto &pair : pairs)
    {
        if (!isFirst)
        {
            std::cout << ", ";
        }
        std::cout << "{" << pair.first << ", " << pair.second << "}";
        isFirst = false;
    }
    std::cout << "}" << std::endl;
}
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
class Solution1
{
public:
    vector<string> findRelativeRanks(vector<int> &score)
    {
        int n = score.size();
        vector<pair<int, int>> arr;
        string desc[3] = {"Gold Medal", "Silver Medal", "Bronze Medal"};
        for (int i = 0; i < n; i++)
        {
            arr.emplace_back(make_pair(score[i], i));
        }
        sort(arr.begin(), arr.end());
        printPairs(arr);
        vector<string> ans(n);
        for (int i = 0; i < n; i++)
        {
            if (i >= 3)
            {
                ans[arr[i].second] = to_string(i + 1);
            }
            else
            {
                ans[arr[i].second] = desc[i];
            }
        }
        return ans;
    }
};

vector<string> findRelativeRanks(vector<int> &score)
{
    int n = score.size();
    string desc[3] = {"Gold Medal", "Silver Medal", "Bronze Medal"};
    vector<pair<int, int>> arr;

    for (int i = 0; i < n; ++i)
    {
        arr.emplace_back(make_pair(-score[i], i));
    }
    sort(arr.begin(), arr.end());
    printPairs(arr);
    vector<string> ans(n);
    for (int i = 0; i < n; ++i)
    {
        if (i >= 3)
        {
            ans[arr[i].second] = to_string(i + 1);
        }
        else
        {
            ans[arr[i].second] = desc[i];
        }
    }
    return ans;
}

int main()
{
    vector<int> score = {10, 3, 8, 9};
    Solution1 s;

    vector<string> s1 = s.findRelativeRanks(score);
    vector<string> s2 = findRelativeRanks(score);
    printVector(s1);
    printVector(s2);
    return 0;
}