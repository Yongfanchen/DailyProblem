
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
    vector<int> answer;
    int base, count, maxCount;
    void update(int x)
    {
        if (x == base)
        {
            ++count;
        }
        else
        {
            count = 1;
            base = x;
        }
        if (count == maxCount)
        {
            answer.push_back(base);
        }
        if (count > maxCount)
        {
            maxCount = count;
            answer = vector<int>{base};
        }
    }
    vector<int> findMode(TreeNode *root)
    {
        vector<int> res = inorderTravesal(root);
        for (int i = 0; i = res.size(); i++)
        {
            update(res[i]);
        }
        return answer;
    }
    vector<int> inorderTravesal(TreeNode *root)
    {
        vector<int> res;
        stack<TreeNode *> stk;
        while (root != nullptr)
        {
            stk.emplace(root);
            root = root->left;
        }
        while (!stk.empty())
        {
            TreeNode *t = stk.top();
            res.push_back(t->val);
            stk.pop();
            TreeNode *r = t->right;
            while (r != nullptr)
            {
                stk.emplace(r);
                r = r->left;
            }
        }
        return res;
    }
};


vector<int> inorderTree(TreeNode *root)
{
    vector<int> res;
    stack<TreeNode *> stk;
    while (root != nullptr)
    {
        stk.emplace(root);
        root = root->left;
    }
    while (!stk.empty())
    {
        TreeNode *t = stk.top();
        res.push_back(t->val);
        TreeNode *r = t->right;
        while (r != nullptr)
        {
            stk.emplace(r);
            r = r->left;
        }
    }
    return res;
}
