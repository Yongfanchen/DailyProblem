#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x, ListNode* next): val(0), next(next) {} 
};

bool isPalidrome(ListNode *head) {
    vector<int> temp;
    while (head != nullptr) {
        temp.emplace_back(head->val);
        head=head->next;
    }

    int size = temp.size() - 1;
    int i = 0;
    while (i < size) {
        if(temp[i++] != temp[size--]) {
            return false;
        }
    }
    return true;
}