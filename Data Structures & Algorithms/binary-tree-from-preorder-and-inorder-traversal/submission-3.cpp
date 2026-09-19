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
//                current root
    //                 ↓
// preorder: [ ROOT | LEFT SUBTREE | RIGHT SUBTREE ]
//            ↑        ↑              ↑
//         preStart  preStart+1    preStart+leftSize+1

    TreeNode* solve(int preStart,int preEnd,vector<int>&preorder,int inStart,int inEnd,vector<int>&inorder,unordered_map<int,int>&ump){
        // No elements in this subtree
        if (preStart > preEnd || inStart > inEnd) return NULL;
        // Find root in inorder
        int indx=ump[preorder[preStart]];
        TreeNode *root = new TreeNode(preorder[preStart]);
        // Number of nodes in left subtree
        int leftSize = indx - inStart;
        //left subtree
        root->left=solve(preStart+1,preStart+leftSize,preorder,inStart,indx-1,inorder,ump);
        //right subtree
        root->right=solve(preStart+leftSize+1,preEnd,preorder,indx+1,inEnd,inorder,ump);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>ump;
        for(int i=0;i<inorder.size();i++){
            ump[inorder[i]]=i;
        }
        return solve(0,preorder.size()-1,preorder,0,inorder.size()-1,inorder,ump);
    }
};
