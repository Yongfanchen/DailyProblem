#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
bool wordPattern(string pattern, string s) {
    unordered_map<string, char> str2ch;
    unordered_map<char, string> ch2str;
    int n = s.length();
    int i = 0;
    for (auto ch : pattern) {
        if (i >= n) {
            return false;
        }
        int j = i;
        while (j < n && s[j] != ' ') j++;
        const string &tmp = s.substr(i, j - i);
        if (str2ch.count(tmp) && str2ch[tmp] != ch) {
            return false;
        }
        if (ch2str.count(ch) && ch2str[ch] != tmp) {
            return false;
        }
        str2ch[tmp] = ch;
        ch2str[ch] = tmp;
        i = j + 1;
    }
    return i >= n;
}
//你是真的一个糟老头子
