#include <algorithm>
#include <cctype>
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
#include <unordered_set>
using namespace std;

// Definition for a Node.
class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

class Solution
{
public:
    vector<int> res;
    vector<int> preorder(Node *root)
    {
        // vector<int> res;
        if (root == nullptr)
            return res;
        res.emplace_back(root->val);
        for (auto &node : root->children)
        {
            preorder(node);
        }
        return res;
    }
};
// 换一种写法
class Solution1
{
public:
    void helper(const Node *root, vector<int> &res)
    {
        if (root == nullptr)
        {
            return;
        }
        res.emplace_back(root->val);
        for (auto &ch : root->children)
        {
            helper(ch, res);
        }
    }
    vector<int> preorder(Node *root)
    {
        vector<int> res;
        helper(root, res);
        return res;
    }
};
