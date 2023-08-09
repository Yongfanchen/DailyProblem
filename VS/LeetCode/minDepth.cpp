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
		//���ϵ��±�����������ÿһ��
		while (!q.empty()) {
			int sz = q.size();

			//�����ұ���ÿһ���ÿ���ڵ�
			for (int i = 0; i < sz; i++) {
				TreeNode* cur = q.front();
				q.pop();
				if (cur->left == nullptr && cur->right == nullptr) return depth;
				//����һ��ڵ�������
				if (cur->left != nullptr) {
					q.push(cur->left);
				}
				if (cur->right != nullptr) {
					q.push(cur->right);
				}
			}
			//ÿ����һ��ͼ�1
			depth++;
		}
		return depth;
	}
};