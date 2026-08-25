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
    bool hasCycle(ListNode* head) {
        if (head == nullptr) return false;
        auto pslow = head;
        auto pfast = pslow->next;
        while (pfast!=nullptr){
            if (pfast == pslow) return true;
            pfast = pfast->next;
            if (pfast != nullptr){
                pfast = pfast->next;
                pslow = pslow->next;
            }
        }
        return false;
    }
};
