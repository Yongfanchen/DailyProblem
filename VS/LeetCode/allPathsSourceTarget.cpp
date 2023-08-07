#include <algorithm>
#include <cctype>
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;
class Solution {
private:
	vector<vector<int>> res;
public:

	vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
		vector<int> path;
		traverse(graph, 0, path);
		return res;
	}

	void traverse(vector<vector<int>>& graph, int s, vector<int> &  path) {
		path.push_back(s);
		int n = graph.size();
		if (s == n - 1) res.push_back(path);
		for (int v : graph[s]) traverse(graph, v, path);
		path.pop_back();
	}
};