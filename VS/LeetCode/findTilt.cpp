#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};


class Solution {
public:
	int ans = 0;

	int findTilt(TreeNode* root) {
		dfs(root);
		return ans;
	}

	int dfs(TreeNode* node) {
		if (node == nullptr)
			return 0;

		int sumLeft = dfs(node->left);
		int sumRight = dfs(node->right);
		ans += abs(sumLeft - sumRight);
		return sumLeft + sumRight + node->val;
	}
};
template <typename T>
T max(T t1, T t2) {
	if (t1 > t2) {
		return t1;
	} else {
		t2;
	}
}





void print(const string &s) {
	int max = (1, 4);
	if (max > 3) {
		{

		}

	}
}



int main() {

}