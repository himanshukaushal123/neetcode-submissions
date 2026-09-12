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

    bool preorder(TreeNode * root,TreeNode* subRoot){
        if(root==NULL)return false;

        if(root->val == subRoot->val){
            if(isSameTree(root,subRoot))return true;
        }
        if(preorder(root->left,subRoot))return true;
  
        if(preorder(root->right,subRoot))return true;
        
        return false;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return preorder(root,subRoot);
    }
};
