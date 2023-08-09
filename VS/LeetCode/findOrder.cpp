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

	//��¼����������
	vector<int> postorder;
	//��¼�Ƿ���ڻ�
	bool hasCycle = false;
	vector<bool> visited, onPath;

public:
	//������
	vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

		vector<vector<int>> graph = buildGraph(numCourses, prerequisites);
		visited = vector<bool>(numCourses, false);
		onPath = vector<bool>(numCourses, false);

		//��ʼ����ͼ
		for (int i = 0; i < numCourses; i++) {
			traverse(graph, i);

		}
		//�л�ͼ�޷�������������
		if (hasCycle) {
			return {};
		}
		//�������������Ϊ����������
		reverse(postorder.begin(), postorder.end());
		vector<int> res(numCourses);
		for (int i = 0; i < numCourses; i++) {
			res[i] = postorder[i];
		}
		return res;
	}
	//ͼ��������
	void traverse(vector<vector<int>> &graph, int s) {
		if (onPath[s]) {
			//���ֻ�
			hasCycle = true;
		}
		if (visited[s] || hasCycle) {
			return;
		}

		//ǰ�����λ��
		onPath[s] = true;
		visited[s] = true;
		for (int t : graph[s]) {
			traverse(graph, t);
		}
		//�������λ��
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

//�Լ���˺һ��
class Solution {
public:
	//��¼��������Ľ��
	vector<int> postorder;
	//��¼�Ƿ���ڻ�
	bool hasCycle = false;
	vector<bool> visited, onPath;

	//������
	vector<int> findOrder(int numCourses, vector<vector<int>>&prerequisites) {
		visited = vector<bool>(numCourses);
		onPath = vector<bool>(numCourses);
		vector<vector<int>> graph = buildGraph(numCourses, prerequisites);
		for (int i = 0; i < numCourses; i++) {
			traverse(graph, i);
		}
		if (hasCycle) {
			return {};
		}
		reverse(postorder.begin(), postorder.end());
		return postorder;
	}
	void traverse(vector<vector<int>> &graph, int s) {
		if (onPath[s]) {
			hasCycle = true;
		}

		if (visited[s] || hasCycle) {
			return;
		}

		//ǰ��λ��
		onPath[s] = true;
		visited[s] = true;
		for (int t : graph[s]) {
			traverse(graph, t);
		}
		//����λ��
		postorder.push_back(s);
		onPath[s] = false;
	}

	vector<vector<int>> buildGraph(int numCourses, vector<vector<int>> &prerequisites) {
		vector<vector<int>> graph(numCourses);
		for (int i = 0; i < numCourses; i++) {
			graph[i] = {};
		}
		for (auto & pre : prerequisites) {
			int from = pre[1];
			int to = pre[0];
			graph[from].push_back(to);
		}
		return graph;
	}
};