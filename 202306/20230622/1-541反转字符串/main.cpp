
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <stack>
#include <cctype>
using namespace std;

string reverseStr(string s, int k)
{
    int size = s.size();
    std::cout << "size = " << size << endl;
    if (size <= k)
    {
        reverse(s.begin(), s.end());
        return s;
    }
    // reverse函数用法
    // reverse(vec.begin() + 1, vec.end() + 4) 反转的结果是[1,4)
    int remain = size % (2 * k);
    if (remain / k)
    {
        int postNum = remain % k;
        reverse(s.end() - postNum - k, s.end() - postNum);
    }
    std::cout << "remain = " << remain << endl;
    int count = (size - remain) / k;
    std::cout << "count = " << count << endl;
    for (int i = 1; i <= count; i += 2)
    {
        std::cout << "(i - 1) * k = " << (i - 1) * k << endl;
        std::cout << "i * k = " << i * k << endl;
        reverse(s.begin() + (i - 1) * k, s.begin() + i * k);
    }
    return s;
}
string reverseStr(string s, int k)
{
    int n = s.length();
    for (int i = 0; i < n; i += 2 * k)
    {
        reverse(s.begin() + i, s.begin() + min(i + k, n));
    }
    return s;
}
int main()
{
    string s = "abcdefg";
    int k = 2;
    // Solution s;
    string res = reverseStr(s, k);
    std::cout << res << endl;
    return 0;
}