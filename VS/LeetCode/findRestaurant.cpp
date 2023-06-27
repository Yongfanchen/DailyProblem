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
	vector<string> findRestaurant(vector<string>& list1, vector<string>& list2)
	{
		int n1 = list1.size();
		int n2 = list2.size();
		unordered_map<string, int> hashmap;
		for (int i = 0; i < n1; i++)
		{
			hashmap[list1[i]] = i;
		}
		int minSum = INT_MAX;
		vector<string> res;
		for (int i = 0; i < n2; i++)
		{
			if (hashmap.count(list2[i]) > 0)
			{
				int j = hashmap[list2[i]];
				if (i + j < minSum)
				{
					res.clear();
					res.push_back(list2[i]);
					minSum = i + j;
				}
				else if (i + j == minSum)
				{
					res.push_back(list2[i]);
				}
			}
		}
		return res;
	}
};