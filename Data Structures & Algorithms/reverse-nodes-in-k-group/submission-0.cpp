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
    ListNode * reverse(ListNode*head){
        ListNode *prev=NULL;
        while(head!=NULL){
            ListNode *nex=head->next;
            head->next=prev;
            prev=head;
            head=nex;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        // find the length
        int count=0;
        ListNode * temp = head;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        // check number of groyp can be formed
        int group = count / k;
        ListNode *end=head;
        ListNode *start=end;
        ListNode *preEnd=NULL;
        ListNode *newhead=head;
        while(group--){
             // move end exactly k-1 times.
            int cnt = 1;
            while (cnt < k) {
                end = end->next;
                cnt++;
            }
            // save node after current group
            ListNode *next=end->next;
            // break the current group
            end->next=NULL;
            // revese the current group
            ListNode *revese_head_node=reverse(start);

            // 'start' is now the tail of the reversed group
            // Save it before changing start.
            ListNode* groupTail = start;

            // attach the current node to the origianl ll
            if(preEnd != NULL){
                preEnd->next=revese_head_node;
            }else{
                newhead=revese_head_node;
            }
            
            // connect reversed group's tail to the next group
            groupTail->next = next;
            // preEnd should point to the tail of the reversed group
            preEnd = groupTail;
            
            start=next;
            end=next;
        }
        return newhead;

    }
};
