// 0 ms | 12.9 MB
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // If both are NULL
        if(p==NULL && q==NULL)
        return true;

        // if one is null other is not
        if(p==NULL || q==NULL)
        return false;
        
        // compare both values
        if(p->val!=q->val)
        return false;
        
        // compare left and right
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);


    }
};