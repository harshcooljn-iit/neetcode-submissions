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

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        auto cmp = [](ListNode* a, ListNode* b){
            return a->val > b->val; // this will give min heap (reverse comparison for heaps compared to std::sort)
        };
        
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);

        for (auto l: lists){
            if (l != nullptr){
                pq.push(l);
            }
        }
        ListNode* dummy = new ListNode();
        ListNode* tail = dummy;
        while (!pq.empty()){
            auto l = pq.top();
            pq.pop();
            tail->next = l;
            tail = tail->next;
            l = l->next;
            if (l != nullptr){
                pq.push(l);
            }
        }

        return dummy->next;
    }

    ListNode* merge2Lists(ListNode* l1, ListNode* l2){
        ListNode* dummy = new ListNode();
        auto tail = dummy;
        while (l1!=nullptr && l2!=nullptr){
            if (l1->val < l2->val){
                tail->next = l1;
                l1 = l1->next;
            }
            else{
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        if (l1 != nullptr){
            tail->next = l1;
        }
        if (l2 != nullptr){
            tail->next = l2;
        }
        return dummy->next;
    }
};
