#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <stack>
#include <cctype>
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
    int maxDepth(Node *root)
    {
        // int max = 0;
        if (root == nullptr)
            return 0;
        int maxCount = 0;
        vector<Node *> mychildren = root->children;
        for (auto child : mychildren)
        {
            maxCount = max(maxCount, maxDepth(child) + 1);
        }
        return maxCount;
    }
};