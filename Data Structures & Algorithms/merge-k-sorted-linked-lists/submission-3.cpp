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
        // Now we can merge the lists 2 at a time
        if (lists.size() == 0) return nullptr;
        while (lists.size() > 1){
            vector<ListNode*> merged;
            merged.reserve((lists.size()+1)/2);
            for (int i=0;i<lists.size();i+=2){
                ListNode* l1 = lists[i];
                ListNode* l2 = i+1<lists.size()?lists[i+1]:nullptr;
                ListNode* l3 = merge2Lists(l1,l2);
                merged.push_back(l3);
            }
            lists = move(merged);
        }
        return lists[0];
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
