#include <algorithm>
#include <cctype>
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <set>
#include <array>
using namespace std;
class Solution {
public:
	int minimumSwitchingTimes(vector<vector<int>>& source, vector<vector<int>>& target)
	{
		vector<int> temp1;
		vector<int> temp2;
		int m = source.size(), n = source[0].size();
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				temp1.emplace_back(source[i][j]);
				temp2.emplace_back(target[i][j]);
			}
		}
		int sum = 0;
		for (auto iter : temp1) {
			if (find(temp2.begin(), temp2.end(), iter)!=temp2.end()) {
				temp2.erase(find(temp2.begin(), temp2.end(), iter));
			}
			else {
				sum++;
			}
		}
		return sum;
	}
};
//int main()
//{
//	//source = [[1,3],[5,4]], target = [[3,1],[6,5]]
//	vector<vector<int>> source = {{1,3},{5,4}};
//	vector<vector<int>> target = {{3,1},{6,5}};
//}