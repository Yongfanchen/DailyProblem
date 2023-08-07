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
#include <cmath>
#include <map>
using namespace std;
class Solution {
private:

	//记录后序遍历结果
	vector<int> postorder;
	//记录是否存在环
	bool hasCycle = false;
	vector<bool> visited, onPath;

public:
	//主函数
	vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

		vector<vector<int>> graph = buildGraph(numCourses, prerequisites);
		visited = vector<bool>(numCourses, false);
		onPath = vector<bool>(numCourses, false);

		//开始遍历图
		for (int i = 0; i < numCourses; i++) {
			traverse(graph, i);

		}
		//有环图无法进行拓扑排序
		if (hasCycle) {
			return {};
		}
		//逆后序遍历结果即为拓扑排序结果
		reverse(postorder.begin(), postorder.end());
		vector<int> res(numCourses);
		for (int i = 0; i < numCourses; i++) {
			res[i] = postorder[i];
		}
		return res;
	}
	//图遍历函数
	void traverse(vector<vector<int>> &graph, int s) {
		if (onPath[s]) {
			//发现环
			hasCycle = true;
		}
		if (visited[s] || hasCycle) {
			return;
		}
		
		//前序遍历位置
		onPath[s] = true;
		visited[s] = true;
		for (int t : graph[s]) {
			traverse(graph, t);
		}
		//后序遍历位置
		postorder.push_back(s);
		onPath[s] = false;
	}

	vector<vector<int>> buildGraph(int numCourses, vector<vector<int>> &prerequisites) {
		vector<vector<int>> res(numCourses);
		for (int i = 0; i < numCourses; i++) {
			res[i] = {};
		}
		for (auto & edge : prerequisites) {
			int from = edge[1], to = edge[0];
			res[from].push_back(to);
		}
		return res;
	}
};