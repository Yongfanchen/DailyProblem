#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
using namespace std;
class Solution {
public:
    bool isAllSameCharacter(const string& str, char ch) {
        for (size_t i = 0; i < str.size(); i++) {
            if (str[i] != ch) {
                return false;
            }
        }
        return true;
    }
    string licenseKeyFormatting1(string s, int k) {
        string res;
        int n = s.size();
        if (n < k) {
            return s;
        }
        if (isAllSameCharacter(s, '-') && n < k) {
            return "";
        }

        for (int i = 0; i < n; i++) {
            if (s[i] == '-') {
                continue;
            } else if (s[i] >= 'a' && s[i] <= 'z') {
                res += s[i] + 33 - 'A';
            } else {
                res += s[i];
            }
        }
        int temp = res.size() % k;
        int ressize = res.size();
        string res1 = "";
        if (temp != 0) {
            res1 += res.substr(0, temp);
            res1 += '-';
            for (int i = temp; i < ressize; i += k) {
                res1 += res.substr(i, k);
                if (i != ressize - k) {
                    res1 += '-';
                }
            }
        } else {
            for (int i = 0; i < ressize; i += k) {
                res1 += res.substr(i, k);
                if (i != ressize - k) {
                    res1 += '-';
                }
            }
        }
        return res1;
    }

    string licenseKeyFormatting(string s, int k) {
        string ans;
        int cnt = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] != '-') {
                ans.push_back(toupper(s[i]));
                cnt++;
                if (cnt % k == 0) {
                    ans.push_back('-');
                }
            }
        }
        if (ans.size() > 0 && ans.back() == '-') {
            ans.pop_back();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    Solution s;
    string res = s.licenseKeyFormatting1("-----------", 100);
    cout << res << endl;
    return 0;
}


