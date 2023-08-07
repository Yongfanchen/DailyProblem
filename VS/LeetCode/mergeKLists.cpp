#include <algorithm>
#include <cctype>
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
#include <queue>
#include <unordered_set>
#include <queue>
#include <functional>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
	ListNode* mergeKLists(vector<ListNode*>& lists)
	{
		if (lists.empty()) return nullptr;

		//先建一个结果
		ListNode* res = new ListNode(-1);

		ListNode* p = res;

		priority_queue < ListNode*, vector<ListNode*>, function<bool(ListNode*, ListNode*) >> pq(
		[](ListNode* a, ListNode *b) { return a->val > b->val; });

		for (auto & head : lists)
		{
			if (head != nullptr)
			{
				pq.push(head);
			}
		}

		while (!pq.empty())
		{
			ListNode* temp = pq.top();
			pq.pop();
			p->next = temp;
			if (temp->next != nullptr)
			{
				pq.push(temp->next);
			}
			p = p->next;

		}
		return res->next;
	}
};

int main()
{


	return 0;
}


