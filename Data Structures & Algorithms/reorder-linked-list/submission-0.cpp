class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;

        while (head != NULL) {
            ListNode* nex = head->next;
            head->next = prev;
            prev = head;
            head = nex;
        }

        return prev;
    }

    void reorderList(ListNode* head) {

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* slow = dummy;
        ListNode* fast = dummy;

        // get the middle element
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // reverse from middle to last
        ListNode* second = slow->next;
        slow->next=NULL;
        second=reverse(second);
        ListNode * ans =head;
        // create reordered list using YOUR approach
        while (head != NULL && second != NULL) {
            ListNode * nex1=head->next;
            ListNode * nex2=second->next;
            head->next=second;
            second->next=nex1;
            head=nex1;
            second=nex2;
        }
        // Copy the values back to the ORIGINAL list
        head = ans;
    }
};
