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
	bool canPlaceFlowers(vector<int>& flowerbed, int n)
	{
		int count = 0;
		int m = flowerbed.size();
		int prev = -1;
		for (int i = 0; i < m; ++i)
		{
			if (flowerbed[i] == 1)
			{
				if (prev < 0)
					count += i / 2;
				else
					count += (i - prev - 2) / 2;
				prev = i;
			}
		}
		if (prev < 0)
			count += (m + 1) / 2;
		else
			count += (m - prev - 1) / 2;
		return count >= n;
	}
};


class Solution1
{
public:
	bool canPlaceFlowers(vector<int> &flowerbed, int n)
	{
		int count = 0;
		int m = flowerbed.size();
		int prev = -1;
		for (int i = 0; i < m; i++)
		{
			if (flowerbed[i] == 1)
			{
				if (prev < 0)
					count += i / 2;
				else
					count += (i - prev - 1) / 2;
				if (count >= n)
					return true;
				prev = i;

			}
		}
		if (prev < 0)
			count += (m + 1) / 2;
		else
			count += (m - prev - 1) / 2;
		return count >= n;
	}
};