//反转列表的思路是什么？
//


struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int val, ListNode *next) : val(val), next(next) {}
};

ListNode* reverseList(ListNode* head) {
    ListNode* pre = head;
    head->next = nullptr;
    ListNode* cur = head->next;
    ListNode* next = cur->next;

}