// 0 ms | 34.4 MB
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
    TreeNode* deleteNode(TreeNode* root, int target) {
        //BASE CONDITIONS
        if(!root)
        return NULL;
        
        if(root->val>target)
        {
          root->left=deleteNode(root->left,target);
          return root;
        }
        
        else if(root->val<target)
        {
          root->right=deleteNode(root->right,target);
          return root;
        }
        
        else
        {
            // Leaf Node
            if(!root->left && !root->right)
            {
                delete root;
                return NULL;
            }
            // 1 child exist
            else if(!root->right)
            {
                TreeNode* temp=root->left;
                delete root;
                return temp;
            }
            
            else if(!root->left)
            {
                TreeNode* temp=root->right;
                delete root;
                return temp;
                
            }
            // 2 child exist
            
            else
            {
                // find the greatest from left side.
                TreeNode*child=root->left;
                TreeNode *parent=root;
                
                
                while(child->right)
                {
                    parent=child;
                    child=child->right;
                    
                }
                
                if(root!=parent)
                {
                    parent->right=child->left;
                    child->left=root->left;
                    child->right=root->right;
                    delete root;
                    return child;
                    
                }
                
                else
                {
                    child->right=root->right;
                    delete root;
                    return child;
                }
            }
            
            
        }
    }
};