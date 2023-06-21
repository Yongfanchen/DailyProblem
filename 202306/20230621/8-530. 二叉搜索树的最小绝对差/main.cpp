#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <stack>
#include <cctype>
using namespace std;
template <typename ValueType>
void printVector(const std::vector<ValueType> &vec)
{
    std::cout << "{";
    for (size_t i = 0; i < vec.size(); ++i)
    {
        if (i > 0)
        {
            std::cout << ", ";
        }
        std::cout << vec[i];
    }
    std::cout << "}" << std::endl;
}
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
    vector<int> inorderTree(TreeNode *root)
    {
        stack<TreeNode *> stk;
        vector<int> res;
        if (root == nullptr)
            return res;
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
            if (r != nullptr)
            {
                stk.emplace(r);
                r = r->left;
            }
        }
        return res;
    }
    int getMinimumDifference(TreeNode *root)
    {
        int min = 9999999;
        vector<int> res = inorderTree(root);
        for (int i = 1; i < res.size(); i++)
        {
            int temp = res[i] - res[i - 1] > 0 ? res[i] - res[i - 1] : res[i - 1] - res[i];
            min = min < temp ? min : temp;
        }
        return min;
    }
};