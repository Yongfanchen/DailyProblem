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
    ListNode *reverseListNode(ListNode *head)
    {
        // 反转链表的思路是什么？你要弄清楚
        // 1，设置一个pre cur next分别表示前 现 后
        // 2，对于每一个cur
        // 3，先记录cur的next
        // 4，将cur的next指向pre
        // 5，分别将pre和cur向后移一位
        ListNode *prev = nullptr;
        ListNode *cur = head;
        ListNode *next = nullptr;
        while (cur != nullptr)
        {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
    ListNode *addTwoNumbers1(ListNode *l1, ListNode *l2)
    {
        // 思路很简单，重点是看你如何将思路实现并且写对
        ListNode *head = nullptr;
        ListNode *tail = nullptr;
        int carry = 0;
        while (l1 || l2)
        {
            int n1 = l1 ? l1->val : 0;
            int n2 = l2 ? l2->val : 0;
            int sum = n1 + n2 + carry;
            if (!head)
            {
                head = new ListNode(sum % 10);
                tail = head;
            }
            else
            {
                tail->next = new ListNode(sum % 10);
                tail = tail->next;
            }
            carry = sum / 10;
            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;
        }
        if (carry > 0)
            tail->next = new ListNode(carry);
        return head;
    }

    // 用自己的思路写一遍
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *head = nullptr;
        ListNode *tail = nullptr;
        int carry = 0;
        while (l1 || l2)
        {
            int n1 = l1 ? l1->val : 0;
            int n2 = l2 ? l2->val : 0;
            int sum = n1 + n2 + carry;
            if (!head)
            {
                head = new ListNode(sum % 10);
                tail = head;
            }
            else
            {
                tail->next = new ListNode(sum % 10);
                tail = tail->next;
            }

            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;
            carry = sum / 10;
        }
        if (carry > 0)
        {
            tail->next = new ListNode(carry);
        }
        return head;
    }
};