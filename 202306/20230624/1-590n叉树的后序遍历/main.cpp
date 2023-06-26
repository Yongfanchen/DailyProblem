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
    vector<int> postorder(Node *root)
    {
        if (root == nullptr)
        {
            return res;
        }
        for (auto &node : root->children)
        {
            postorder(node);
        }
        res.emplace_back(root->val);
        return res;
    }
};