
#include <algorithm>
#include <cctype>
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  int ans;
  int dfs(TreeNode* root) {
    // int ans = 0;
    if (root == nullptr) {
      return 0;
    }
    int l = dfs(root->left);
    int r = dfs(root->right);
    int temp = abs(l - r);
    ans += temp;
    return l + r + root->val;
  }
  int findTilt(TreeNode* root) {
    dfs(root);
    return ans;
  }
};