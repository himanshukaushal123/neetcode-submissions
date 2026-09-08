/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
     // create a map
     unordered_map<Node * , Node * >ump;
     Node * curr=head;
     while(curr!=NULL){
     	ump[curr]=new Node(curr->val);
     	curr=curr->next;
     }
     // connect the next and random

     curr=head;
     while(curr!=NULL){
     	ump[curr]->next=ump[curr->next];
     	ump[curr]->random=ump[curr->random];
     	curr=curr->next;
     }
     return ump[head];
    }
};
