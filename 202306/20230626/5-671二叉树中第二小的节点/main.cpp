#include <algorithm>
#include <cctype>
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
#include <set>
#include <unordered_set>
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
    void inorder(TreeNode *root, set<int> &set)
    {
        if (root == nullptr)
            return;
        inorder(root->left, set);
        set.insert(root->val);
        inorder(root->right, set);
    }
    int findSecondMinimumValue(TreeNode *root)
    {
        set<int> setRes;
        inorder(root, setRes);
        if (setRes.size() == 1)
            return -1;
        auto it = setRes.begin();
        ++it;
        return *it;
    }
};