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
        if (lists.empty()) {
            return NULL;
        }

        priority_queue<
            pair<int, ListNode*>,
            vector<pair<int, ListNode*>>,
            greater<pair<int, ListNode*>>
        > minHeap;

        // Put the first node of every list into the heap
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] != NULL) {
                minHeap.push({lists[i]->val, lists[i]});
            }
        }
        // time comexity of above loop -- k * logk
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;

        while (!minHeap.empty()) {// k*N

            // Get the smallest node
            auto [value, node] = minHeap.top();// log k
            minHeap.pop();// log k

            // Attach it to answer
            temp->next = node;
            temp = temp->next;

            // Put the next node from the same list into heap
            if (node->next != NULL) {
                minHeap.push({node->next->val, node->next});//log k
            }
        }
        // while loop -- k*N*3logk
        return dummy->next;
    }

};