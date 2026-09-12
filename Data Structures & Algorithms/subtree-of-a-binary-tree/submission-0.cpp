/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool isSameTree(TreeNode *p,TreeNode *q){
        if(p==NULL || q==NULL) return (p==q);
        return (p->val==q->val) && isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
    }

    int preorder(TreeNode * root,TreeNode* subRoot){
        if(root==NULL)return 0;

        if(root->val == subRoot->val){
            if(isSameTree(root,subRoot))return -1;
        }
        int lh=preorder(root->left,subRoot);
        if(lh==-1)return -1;
        int rh=preorder(root->right,subRoot);
        if(rh==-1)return -1;
        return 0;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return preorder(root,subRoot)==-1;
    }
};
