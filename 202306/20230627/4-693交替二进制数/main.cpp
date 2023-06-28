#include <algorithm>
#include <cctype>
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution
{
public:
  string inttostringTwo(int n)
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
    reverse(res.begin(), res.end());
    return res;
  }
  bool hasAlternatingBits(int n)
  {
    string res = inttostringTwo(n);
    std::cout << "res = " << res << endl;
    int size = res.length();
    if (res[0] == '1')
    {
      std::cout << "if (res[0] == '1')" << endl;
      for (int i = 1; i < size; i++)
      {
        if (i % 2 == 1)
        {
          if (res[i] == '1')
            return false;
        }
        else
        {
          if (res[i] == '0')
            return false;
        }
      }
      return true;
    }
    else
    {
      for (int i = 1; i < size; i++)
      {
        if (i % 2 == 1)
        {
          if (res[i] == '0')
            return false;
        }
        else
        {
          if (res[i] != '1')
            return false;
        }
      }
      return true;
    }
  }
};
bool hasAlternatingBits(int n)
{
  int prev = 2;
  while (n > 0)
  {
    int cur = n % 2;
    if (prev == cur)
      return false;
    prev = cur;
    n = n / 2;
  }
  return true;
}
int main()
{
  Solution s;
  string res = s.inttostringTwo(5);
  string res1 = s.inttostringTwo(7);
  string res2 = s.inttostringTwo(11);
  bool is = s.hasAlternatingBits(5);
  bool is2 = hasAlternatingBits(5);
  std::cout << "is2 = " << is2 << endl;
  std::cout << is << endl;
  std::cout << res << endl;
  std::cout << res1 << endl;
  std::cout << res2 << endl;
}