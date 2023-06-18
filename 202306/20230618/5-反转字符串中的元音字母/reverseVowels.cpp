#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
using namespace std;

string reverseVowels1(string s) {
    string res = s;
    int n = res.size();
    vector<char> latters = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    vector<int> tempInt;
    vector<char> tempChar;

    //找出所有的元音字母并记录
    for (int i = 0; i < n; i++) {
        auto iter = find(latters.begin(), latters.end(), res[i]);
        if (iter != latters.end()) {
            tempInt.emplace_back(i);
            tempChar.emplace_back(res[i]);
            cout << res[i];
        }
    }
    //反转tempChar
    int tempCharsize = tempChar.size();
    for (int left = 0, right = tempCharsize - 1; left < right; left++, right--) {
        swap(tempChar[left], tempChar[right]);
    }
    for (auto it : tempChar) {
        cout << it;
    }
    for (auto it : tempInt) {
        cout << it;
    }
    for (int i = 0; i < n; i++) {
        auto iter = find(tempInt.begin(), tempInt.end(), tempInt[i]);
        if (iter != tempInt.end()) {
            res[tempInt[i]] = tempChar[i];
        }
    }
    return res;
}




string reverseVowels(string s) {
    //返回true 则是辅音 返回false则是元音 
    auto isVowel = [vowels = "aeiouAEIOU"s](char ch) {
        return vowels.find(ch) != string::npos;
    };

    int n = s.size();
    int i = 0, j = n - 1;
    while (i < j) {
        while (i < n && !isVowel(s[i])) {
            ++i;
        }
        while(j > 0 && !isVowel(s[j])) {
            --j;
        }
        if (i < j) {
            swap(s[i], s[j]);
            ++i;
            --j;
        }
    }
    return s;
}


int main() {
    string s = "leetcode";
    string res = reverseVowels(s);
    cout << res << endl;
    return 0;
}