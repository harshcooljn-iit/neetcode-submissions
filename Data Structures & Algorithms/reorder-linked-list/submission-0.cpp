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

    void reverseList(ListNode** head){
        ListNode* cur = *head;
        ListNode* prev = nullptr;
        while (cur!=nullptr){
            auto temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }
        *head = prev;
    }

    ListNode* splitList(ListNode* head){
        auto pslow = head;
        auto pfast = pslow->next;
        while (pfast!=nullptr){
            pfast = pfast->next;
            if (pfast != nullptr){
                pfast = pfast->next;
                pslow = pslow->next;
            }
        }
        auto head2 = pslow->next;
        pslow->next = nullptr;
        return head2;
    }    

    void mergeAlternate(ListNode* h1, ListNode* h2){
        auto cur1 = h1;
        auto cur2 = h2;
        while (cur1 && cur2){
            auto n1 = cur1->next;
            auto n2 = cur2->next;
            cur1->next = cur2;
            cur2->next = n1;
            cur2 = n2;
            cur1 = n1;
        }
        return;
    }

    void reorderList(ListNode* head) {
        if (head==nullptr || head->next==nullptr) return;
        auto h2 = splitList(head);
        reverseList(&h2);
        mergeAlternate(head, h2);
    }
};
