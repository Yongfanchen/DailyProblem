#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
using namespace std;

//这你的脑子在想什么东西啊？？？？？
//
vector<string> fizzBuzz(int n) {
    vector<string> resv;
    for (int i = 1; i <= n; i++) {
        string ans;
        if (i % 3 == 0) {
            ans += "Fizz";
        }
        if (i % 5 == 0) {
            ans += "Buzz";
        }
        if (ans.size() == 0) {
            ans += to_string(i);
        }
        resv.push_back(ans);
    }
    return resv;
}

