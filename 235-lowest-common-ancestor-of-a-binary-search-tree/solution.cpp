// 31 ms | 23.6 MB
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(!root)
        return NULL;

        // Move left
        if(root->val >p->val && root->val> q->val)
        return lowestCommonAncestor(root->left,p,q);

        // Move right
        else if(root->val <p->val && root->val< q->val)
        return lowestCommonAncestor(root->right,p,q);

        //path diverge
        else
        return root;
    }
};