
#include <algorithm>
#include <cctype>
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  bool isSameTree(TreeNode *p, TreeNode *q) {
    if (p == nullptr && q == nullptr) {
      return true;
    } else if (p == nullptr || q == nullptr) {
      return false;
    } else if (p->val != q->val) {
      return false;
    } else {
      return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
  }
  bool isSubtree(TreeNode *root, TreeNode *subRoot) {
    stack<TreeNode *> stk;
    while (root != nullptr) {
      stk.emplace(root);
      root = root->left;
    }
    while (!stk.empty()) {
      TreeNode *t = stk.top();
      if (isSameTree(t, subRoot)) {
        return true;
      }
      stk.pop();
      TreeNode *r = t->right;
      while (r != nullptr) {
        stk.emplace(r);
        r = r->left;
      }
    }
    return false;
  }
};