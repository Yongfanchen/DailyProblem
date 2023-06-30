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
// 你在干什么呢？请你把题目看清楚好不好？
class Solution
{
public:
    bool isContainer1(unordered_map<char, int> hashmap, string word)
    {
        for (auto &charInt : hashmap)
        {
            if (count(word.begin(), word.end(), charInt.first) < charInt.second)
            {
                return false;
            }
        }
        return true;
    }
    string shortestCompletingWord(string licensePlate, vector<string> &words)
    {
        set<char> letters;
        unordered_map<char, int> hashmap;
        for (auto &let : licensePlate)
        {
            if ('a' <= let && let <= 'z' || 'A' <= let && let <= 'Z')
            {
                if ('A' <= let && let < 'Z')
                {
                    hashmap[tolower(let)]++;
                }
                else
                {
                    hashmap[let]++;
                }
            }
        }
        int minLen = INT_MAX;
        string res;
        for (auto &word : words)
        {
            if (isContainer1(hashmap, word))
            {
                if (word.length() < minLen)
                {
                    minLen = word.length();
                    res = word;
                }
            }
        }
        return res;
    }
};

int main()
{
    string licensePlate = "1s3 PSt";
    vector<string> words = {"step", "steps", "stripe", "stepple"};
    Solution s;
    string res = s.shortestCompletingWord(licensePlate, words);
    return 0;
}
class Solution
{
public:
    string shortestCompletingWord(string licensePlate, vector<string> &words)
    {
        array<int, 26> cnt{};
        for (char ch : licensePlate)
        {
            if (isalpha(ch))
            {
                ++cnt[tolower(ch) - 'a'];
            }
        }
        int idx = -1;
        for (int i = 0; i < words.size(); ++i)
        {
            array<int, 26> c{};
            for (char ch : words[i])
            {
                ++c[ch - 'a'];
            }
            bool ok = true;
            for (int j = 0; j < 26; ++j)
            {
                if (c[j] < cnt[j])
                {
                    ok = false;
                    break;
                }
            }
            if (ok && (idx < 0 || words[i].length() < words[idx].length()))
            {
                idx = i;
            }
        }
        return words[idx];
    }
};