#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
using namespace std;
int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int gsize = g.size();
    int ssize = s.size();
    int res = 0;
    int i = 0, j = 0;   //LeetCode上面会显示没有初始化
    while (i < gsize && j < ssize) {
        std::cout << s[j] << std::endl;
        std::cout << g[i] << std::endl;
        if (s[j] >= g[i]) {
            res++;
            j++;
            i++;
        } else {
            j++;
        }
    }
    return res;
}


int main() {
    vector<int> g = {1, 2};
    vector<int> s = {1, 2, 3};
    int res = findContentChildren(g, s);
    std::cout << "main of res = ";
    std::cout << res << std::endl;
    return 0;
}