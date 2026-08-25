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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = nullptr;
        if (list1 != nullptr && list2!=nullptr){
            if (list1->val < list2->val){
                head = list1;
                list1 = list1->next;
            }
            else{
                head = list2;
                list2 = list2->next;
            }
        }
        else if (list1!=nullptr){
            head = list1;
            list1 = list1->next;
        }
        else if (list2!=nullptr){
            head = list2;
            list2 = list2->next;
        }
        auto cur = head;
        while (list1!=nullptr && list2!=nullptr){
            auto temp1 = list1->next;
            auto temp2 = list2->next;
            if (list1->val < list2->val){
                cur->next = list1;
                list1 = temp1;
            }
            else{
                cur->next = list2;
                list2 = temp2;
            }
            cur = cur->next;
        }
        if (list1!=nullptr){
            cur->next = list1;
        }
        else if (list2!=nullptr){
            cur->next = list2;
        }
        return head;
    }
};
