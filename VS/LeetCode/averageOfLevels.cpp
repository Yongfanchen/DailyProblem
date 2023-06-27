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

//   Definition for a binary tree node.
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr)
	{}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr)
	{}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right)
	{}
};

class Solution
{
public:
	vector<vector<int>> levelOrder(TreeNode *root)
	{
		vector<vector<int>> res;
		if (root == nullptr)
			return res;

		queue<TreeNode *> q;
		q.push(root);

		while (!q.empty())
		{
			int levelSize = q.size();
			vector<int> currentLevel;
			for (int i = 0; i < levelSize; i++)
			{
				TreeNode *node = q.front();
				q.pop();
				currentLevel.push_back(node->val);
				if (node->left != nullptr)
					q.push(node->left);
				if (node->right != nullptr)
					q.push(node->right);
			}
			res.push_back(currentLevel);
		}
		return res;
	}
	vector<double> averageOfLevels(TreeNode *root)
	{
		vector<double> dres;
		vector<vector<int>> res = levelOrder(root);
		for (auto &nums : res)
		{
			int sum = 0;
			for (auto &num : nums)
			{
				sum += num;
			}
			dres.emplace_back((double)(sum / nums.size()));
		}
		return dres;
	}
};
vector<vector<int>> levelOrder1(TreeNode *root)
{
	vector<vector<int>> res;
	if (root == nullptr)
		return res;

	queue<TreeNode *> q;
	q.push(root);

	while (!q.empty())
	{
		int levelSize = q.size();
		vector<int> currentLevel;
		for (int i = 0; i < levelSize; i++)
		{
			TreeNode *node = q.front();
			q.pop();
			currentLevel.push_back(node->val);
			if (node->left != nullptr)
				q.push(node->left);
			if (node->right != nullptr)
				q.push(node->right);
		}
		res.push_back(currentLevel);
	}
	return res;
}
//int main()
//{
//	TreeNode* root = new TreeNode(3);
//	root->left = new TreeNode(9);
//	root->right = new TreeNode(20);
//	root->right->left = new TreeNode(15);
//	root->right->right = new TreeNode(7);
//	vector<vector<int>> res = levelOrder1(root);
//	vector<double> dres;
//	for (auto &nums : res)
//	{
//		double sum = 0;
//		for (auto &num : nums)
//		{
//			sum += (double)num;
//		}
//		dres.emplace_back(sum / nums.size());
//	}
//
//	return 0;
//}


