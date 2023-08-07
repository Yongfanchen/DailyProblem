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
	vector<int> color;
	vector<int> visited;
public:
	bool possibleBipartition(int n, vector<vector<int>>& dislikes) {

		vector<vector<int>> graph = buildGraph(n, dislikes);
		color.resize(n + 1);
		visited.resize(n + 1);

		for (int  i = 1; i <=n; i++) {
			if (!visited[i]) {
				travsere(graph, i);
			}
		}
		return ok;
		
	}

	vector<vector<int>> buildGraph(int n, vector<vector<int>> &dislikes) {
		vector<vector<int>> res(n + 1);
		for (int i = 1; i <= n; i++) {
			res[i] = {};
		}
		for (auto &edge : dislikes) {
			int v = edge[0];
			int w = edge[1];
			res[v].push_back(w);
			res[w].push_back(v);
		}
		return res;
	}

	void travsere(vector<vector<int>> & graph, int w) {
		if (!ok) return;
		visited[w] = true;
		for (int & v : graph[w]) {
			if (!visited[v]) {
				color[v] = !color[w];
				travsere(graph, v);
			} else {
				if (color[v] == color[w]) {
					ok = false;
					return;
				}
			}
		}
	}
};
