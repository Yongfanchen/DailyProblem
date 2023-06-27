#include <algorithm>
#include <cctype>
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
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
    void inOrder(TreeNode *root, vector<int> &res)
    {
        if (root == nullptr)
            return;
        inOrder(root->left, res);
        res.push_back(root->val);
        inOrder(root->right, res);
    }
    bool findTarget(TreeNode *root, int k)
    {
        vector<int> res;
        inOrder(root, res);
        unordered_map<int, int> hashmap;
        for (int i = 0; i < res.size(); i++)
        {
            auto it = hashmap.find(k - res[i]);
            if (it != hashmap.end())
                return true;
            hashmap[res[i]] = i;
        }
        return false;
    }
};