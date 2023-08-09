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
class Solution1 {
private:

	//记录一次递归堆栈中的节点
	vector<bool> onPath;
	//记录遍历过的节点，防止走回头路
	vector<bool> visited;
	//记录图中是否有环
	bool hasCycle = false;

public:
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		vector<vector<int>> graph = buildGraph(numCourses, prerequisites);
		visited = vector<bool>(numCourses);
		onPath = vector<bool>(numCourses);
		for (int i = 0; i < numCourses; i++) {
			traverse(graph, i);
		}
		return !hasCycle;
	}
	void traverse(vector<vector<int>> &graph, int s) {
		if (onPath[s]) {
			hasCycle = true;
		}
		if (visited[s] || hasCycle) {
			return;
		}
		//前序代码位置
		visited[s] = true;
		onPath[s] = true;
		for (int t : graph[s]) {
			traverse(graph, t);
		}
		//后序代码位置
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

//手撕一遍 环检测算法
class Solution {
private:
	bool hasCycle = false;
	vector<bool> onPath;
	vector<bool> visited;
public:
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		vector<vector<int>> graph = buildgraph(numCourses, prerequisites);
		onPath = vector<bool>(numCourses, false);
		visited = vector<bool>(numCourses, false);
		for (int i = 0; i < numCourses; i++) {
			traverse(i, graph);
		}
		return !hasCycle;
	}
	void traverse(int s, vector<vector<int>>& graph) {
		if (onPath[s]) {
			hasCycle = true;
		}
		if (visited[s] || hasCycle) {
			return;
		}

		visited[s] = true;
		onPath[s] = true;
		for (int i : graph[s]) {
			traverse(i, graph);
		}
		//visited[s] = false;
		//这里只需要 onPath[s] = false; why？

		onPath[s] = false;
	}
	//建图算法
	vector<vector<int>> buildgraph(int numCourses, vector<vector<int>> &prerequisites) {

		vector<vector<int>> graph(numCourses);
		for (int i = 0; i < numCourses; i++) {
			graph[i] = {};
		}
		for (auto & prerequisite : prerequisites) {
			int from = prerequisite[1];
			int to = prerequisite[0];
			graph[from].push_back(to);
		}
		return graph;
	}

};