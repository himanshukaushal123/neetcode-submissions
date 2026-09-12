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
    void pathRootNmber(TreeNode * root, vector<TreeNode*>&path,TreeNode * target){
        if(root==NULL)return;
        if(root==target){
            path.push_back(root);
            return;
        }
        path.push_back(root);
        pathRootNmber(root->left,path,target);
        // If target was found in left subtree, don't continue
        if(path.back() == target)
            return;

        pathRootNmber(root->right,path,target);
        // If target was found in right subtree, don't continue
        if(path.back() == target)
            return;

        path.pop_back();
        return;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //path from root to p and to q 
        vector<TreeNode *>p_path;
        vector<TreeNode *>q_path;
        pathRootNmber(root,p_path,p);
        pathRootNmber(root,q_path,q);
        TreeNode *prev=NULL;
        for(int i=0;i<min(p_path.size(),q_path.size());i++){
            if(p_path[i]!=q_path[i]){
                break;
            }
            prev=p_path[i];
        }
        return prev;

    }
};
