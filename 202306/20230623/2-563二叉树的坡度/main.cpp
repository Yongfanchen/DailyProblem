
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <stack>
#include <cctype>
using namespace std;
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
    int absofLR(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        else
        {
            return root->left->val - root->right->val > 0 ? root->left->val - root->right->val : -(root->left->val - root->right->val);
        }
    }
    int findTilt(TreeNode *root)
    {
        // return countNodes(root->left) > countNodes(root->right) ? countNodes(root->left) : countNodes(root->right);
    }
};