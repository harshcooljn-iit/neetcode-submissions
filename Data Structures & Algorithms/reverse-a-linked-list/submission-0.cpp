/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:

    void revers(ListNode* cur, ListNode** head){
        if (cur == nullptr) return;
        if (cur->next == nullptr){
            *head = cur;
        }
        else{
            revers(cur->next, head);
            cur->next->next = cur;
            cur->next = nullptr;
        }
    }

    ListNode* reverseList(ListNode* head) {
        revers(head,&head);
        return head;
    }
};
