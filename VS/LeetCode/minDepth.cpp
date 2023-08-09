#include <algorithm>
#include <cctype>
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <set>
#include <array>
#include <cmath>
#include <map>
#include <queue>
//#include "tree.h"
#include "datastruct.h"
using namespace std;
using namespace Tree;
using namespace ListNode;


class Solution {
public:
	int minDepth(TreeNode* root) {
		if (root == nullptr) return 0;
		queue<TreeNode*> q;
		q.push(root);

		int depth = 1;
		//从上到下遍历二叉树的每一层
		while (!q.empty()) {
			int sz = q.size();

			//从左到右遍历每一层的每个节点
			for (int i = 0; i < sz; i++) {
				TreeNode* cur = q.front();
				q.pop();
				if (cur->left == nullptr && cur->right == nullptr) return depth;
				//将下一层节点放入队列
				if (cur->left != nullptr) {
					q.push(cur->left);
				}
				if (cur->right != nullptr) {
					q.push(cur->right);
				}
			}
			//每增加一层就加1
			depth++;
		}
		return depth;
	}
};