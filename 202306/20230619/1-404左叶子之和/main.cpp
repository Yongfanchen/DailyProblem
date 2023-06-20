
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <queue>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 

class Solution {
public:
	bool isLeafNode(TreeNode* node) {
		return !node->left && !node->right;
	}
	int dfs(TreeNode* root) {
		int ans = 0;
		if (root->left) {
			ans += isLeafNode(root->left) ? root->left->val : dfs(root->left);
		}
		if (root->right && !isLeafNode(root->right)) {
			ans += dfs(root->right);
		}
		return ans;
	}
	int sumOfLeftLeaves(TreeNode* root) {
		return root ? dfs(root) : 0;
	}
};

/*
一个节点为「左叶子」节点，当且仅当它是某个节点的左子节点，并且它是一个叶子结点。因此我们可以考虑对整棵树进行遍历，当我们遍历到节点 
node 时，如果它的左子节点是一个叶子结点，那么就将它的左子节点的值累加计入答案。

遍历整棵树的方法有深度优先搜索和广度优先搜索，下面分别给出了实现代码。

*/

class Solutiondfs {
public:
	//判断是否为叶子节点
    bool isLeafNode(TreeNode* node) {
        return !node->left && !node->right;
    }

    int dfs(TreeNode* node) {
        int ans = 0;
        if (node->left) {
            ans += isLeafNode(node->left) ? node->left->val : dfs(node->left);
        }
        if (node->right && !isLeafNode(node->right)) {
            ans += dfs(node->right);
        }
        return ans;
    }

    int sumOfLeftLeaves(TreeNode* root) {
        return root ? dfs(root) : 0;
    }
};

class Solutionbfs {
public:
    bool isLeafNode(TreeNode* node) {
        return !node->left && !node->right;
    }

    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) {
            return 0;
        }

        queue<TreeNode*> q;
        q.push(root);
        int ans = 0;
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node->left) {
                if (isLeafNode(node->left)) {
                    ans += node->left->val;
                }
                else {
                    q.push(node->left);
                }
            }
            if (node->right) {
                if (!isLeafNode(node->right)) {
                    q.push(node->right);
                }
            }
        }
        return ans;
    }
};


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution03 {
    int sum = 0;
public:
    int sumOfLeftLeaves(TreeNode* root) {        
        sum = 0;
        sumHelper(root,false);
        return sum;
    }

    void sumHelper(TreeNode* root, bool bLeft){//加个参数，代表此结点是左还是右
        if(!root){
            return;
        }
        if(bLeft && !root->left && !root->right){ //如果是左，并且是叶子结点(左右儿子都是空)
            sum+=root->val;
        }

        sumHelper(root->left, true);
        sumHelper(root->right, false);
    }
};

bool isLeafNode(TreeNode* node) {
	return !node->left && !node->right;
}

int sumOfLeftLeaves(TreeNode* root) {
	if (!root) {
		return 0;
	}
	int ans = 0;
	queue<TreeNode*> q;
	q.push(root);
	while (!q.empty()) {
		TreeNode* temp = q.front();
		q.pop();
		if (temp->left) {
			if (isLeafNode(temp->left)) {
				ans += temp->left->val;
			}else {
				q.push(temp->left);
			}
		}
		if (temp->right) {
			if (!isLeafNode(temp->right)) {
				q.push(temp->right);
			}
		}
	}
	return ans;
}