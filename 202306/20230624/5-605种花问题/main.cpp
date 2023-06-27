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
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        int sum = 0;
        int size = flowerbed.size();
        if (flowerbed[0] == 0 && flowerbed[1] == 0 && flowerbed[2] == 1)
        {
            sum++;
            flowerbed[1] = 1;
        }
        for (int i = 1; i < size - 1; i++)
        {
            if (flowerbed[i - 1] == 0 && flowerbed[i] == 0 && flowerbed[i + 1] == 0)
            {
                flowerbed[i] = 1;
                sum++;
            }
        }
        return sum >= n ? true : false;
    }
};