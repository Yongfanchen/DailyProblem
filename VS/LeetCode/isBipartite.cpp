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
	bool ok = true;
	vector<bool> visited;
	vector<bool> color;

public:
	bool isBipartite(vector<vector<int>>& graph) {

		int n = graph.size();
		visited.resize(n);
		color.resize(n);

		for (int v = 0; v < n; v++) {
			if (!visited[v]) {
				traverse(graph, v);
			}
		}
		return ok;
	}

	void traverse(vector<vector<int>> &graph, int v) {

		if (!ok) return;
		visited[v] = true;
		for (int w : graph[v]) {
			if (!visited[w]) {
				color[w] = !color[v];
				traverse(graph, w);
			} else {
				if (color[w] == color[v]) {
					ok = false;
					return;
				}
			}
		}
	}
};