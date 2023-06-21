#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <stack>
#include <cctype>
using namespace std;
class Solution
{
public:
    bool checkPerfectNumber(int num)
    {
        int sum = 0;
        for (int i = 1; i < num; i++)
        {
            if (num % i == 0)
            {
                sum += i;
            }
        }
        if (sum == num)
            return true;
        else
            return false;
    }
};
int main()
{
    Solution s;
    bool s1 = s.checkPerfectNumber(6);
    bool s2 = s.checkPerfectNumber(28);
    bool s3 = s.checkPerfectNumber(496);
    bool s4 = s.checkPerfectNumber(496);
    bool s5 = s.checkPerfectNumber(33550336);
    cout << s1 << s2 << s3 << s4 << s5 << endl;
}