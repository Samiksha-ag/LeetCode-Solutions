// 3 ms | 146.9 MB
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
    int minDepth(TreeNode* root) {
        if(root==NULL)
        return 0;
        
        // both children are null.
        if(!root->left && !root->right)
        return 1;
        
        // only left exist
        if(root->left && !root->right)
        return 1+ minDepth(root->left);

        // only right exist  
        if(root->right && !root->left)
        return 1+ minDepth(root->right);

        
        // 1 for root node
        return 1+ min(minDepth(root->left),minDepth(root->right));
    }
};