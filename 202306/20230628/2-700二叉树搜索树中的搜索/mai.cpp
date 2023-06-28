#include <algorithm>
#include <cctype>
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    void dfs(TreeNode *root, TreeNode **res, int val)
    {
        if (root == nullptr)
            return;
        if (root->val == val)
            *res = root;
        dfs(root->left, res, val);
        dfs(root->right, res, val);
    }
    TreeNode *searchBST(TreeNode *root, int val)
    {
        TreeNode *res = nullptr;
        dfs(root, &res, val);
        return res;
    }
};