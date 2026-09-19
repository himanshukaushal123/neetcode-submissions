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
    // inorder will give sorted array
    long long prev = LLONG_MIN;
    bool inorder(TreeNode* root){
        if(root==NULL)return true;
        
        bool left=inorder(root->left);
        if (!left) return false;
        
        if(root->val<=prev)return false;
        prev=root->val;
        
        bool right=inorder(root->right);
        if (!right) return false;
        
        return true;
    }
    bool isValidBST(TreeNode* root) {
        return inorder(root);
    }
};
