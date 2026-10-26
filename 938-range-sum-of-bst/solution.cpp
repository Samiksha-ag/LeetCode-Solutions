// 0 ms | 64.8 MB
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
    void Find(TreeNode* root, int &sum, int low, int high)
    {
        if(!root)
        return;
        
        // Move left is values are smaller.
        if(root->val>low && root->val>high)
        Find(root->left,sum,low,high);
        
        // Move right if values are greater.
        else if(root->val <low && root->val <high)
        Find(root->right, sum, low, high);
        
        // inorder traversal.(sorted order)
        else
        {
            Find(root->left,sum,low,high);
            sum+=root->val;
            Find(root->right,sum,low,high);
        }
    }


    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum=0;
        Find(root,sum,low,high);
        return sum;
    }
};