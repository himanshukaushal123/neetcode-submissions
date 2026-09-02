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
        if(head==NULL) return false;
        ListNode * dummy=new ListNode(0);
        dummy->next=head;
        ListNode * slow=dummy;
        ListNode * faster=dummy;
        while(faster!=NULL && faster->next!=NULL){
            slow=slow->next;
            faster=faster->next->next;
            if(slow==faster)return true;
        }
        return false;
    }
};
