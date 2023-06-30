#include <algorithm>
#include <cctype>
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
#include <unordered_set>
using namespace std;
class Solution
{
public:
    string getBitsFromInt(int n)
    {
        string res;
        while (n > 0)
        {
            if (n % 2 == 1)
                res += "1";
            else
                res += "0";
            n = n / 2;
        }
        return res;
    }
    bool isPrime(int n)
    {
        if (n == 1)
            return false;
        if (n == 2)
            return true;
        for (int i = 2; i <= n - 1; i++)
        {
            if (n % i == 0)
                return false;
        }
        return true;
    }
    int countPrimeSetBits(int left, int right)
    {
        int sum = 0;
        for (int i = left; i <= right; i++)
        {
            string temp;
            temp = getBitsFromInt(i);
            if (isPrime(count(temp.begin(), temp.end(), '1')))
                sum++;
        }
        return sum;
    }
};
class Solution1
{
    bool isPrime(int x)
    {
        if (x < 2)
        { // 0，1都不是质数
            return false;
        }
        for (int i = 2; i * i <= x; ++i) // 求质数时，只需要比较从2开始 根号n结束
        {
            if (x % i == 0)
            {
                return false;
            }
        }
        return true;
    }

public:
    int countPrimeSetBits(int left, int right)
    {
        int ans = 0;
        for (int x = left; x <= right; ++x)
        {
            if (isPrime(__builtin_popcount(x)))
            { // 计算二进制1的个数
                ++ans;
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    int count = s.countPrimeSetBits(6, 10);
    int i = 0;
    return 0;
}