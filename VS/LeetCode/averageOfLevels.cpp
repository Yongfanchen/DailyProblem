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
//vector<int> midOrder(TreeNode *root)
//{
//	vector<int> res;
//	if (root == nullptr)
//	{
//		return res;
//	}
//	midOrder(root->left);
//	res.push_back(root->val);
//	midOrder(root->right);
//	return res;
//}


void inorder(TreeNode* root, vector<int>& res)
{
	if (root == nullptr)
		return;
	inorder(root->left, res);
	res.push_back(root->val);
	inorder(root->right, res);
}


vector<int> inOrderiter(TreeNode *root)
{
	vector<int> res;
	stack<TreeNode*>stk;
	while (root != nullptr || !stk.empty())
	{
		while (root != nullptr)
		{
			stk.emplace(root);
			root = root->left;
		}
		root = stk.top();
		stk.pop();
		res.push_back(root->val);
		root = root->right;
	}
	return res;
}

//二叉树的迭代算法
vector<int> inorderIIItred(TreeNode* root)
{
	vector<int> res;
	stack<TreeNode*> stk;
	while (root!=nullptr)
	{
		stk.emplace(root);
		root = root->left;
	}
	while (!stk.empty())
	{
		TreeNode *node = stk.top();
		stk.pop();
		res.push_back(node->val);
		node = node->right;
		while (node != nullptr)
		{
			stk.emplace(node);
			node = node->left;
		}
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
//	vector<int> res2 = inOrderiter(root);
//	//vector<int> res;
//	//inorder(root, res);
//	//vector<int> res1 = res;
//
//	return 0;
//}


