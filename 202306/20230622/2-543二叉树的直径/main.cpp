
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
    int Max;
    int depth(TreeNode *rt)
    {
        if (rt == nullptr)
        {
            return 0;
        }
        int L, R;
        L = depth(rt->left);
        R = depth(rt->right);
        if (L + R > Max)
        {
            Max = L + R;
        }
        return max(L, R) + 1;
    }
    int diameterOfBinaryTree(TreeNode *root)
    {
        Max = 0;
        depth(root);
        return Max;
    }
};