// 7 ms | 128 MB
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
    int Burn(TreeNode* root, int &Timer, int start)
    {
        if(!root)
        return 0;
        
        if(root->val==start)
        return -1;
        
        int left=Burn(root->left, Timer, start);
        int right= Burn(root->right, Timer, start);
        
        if(left<0)
        {
            Timer=max(Timer, abs(left)+ right);
            return left-1;
        }
        
        if(right<0)
        {
            Timer=max(Timer,left + abs(right));
            return right-1;
        }
        
        return 1+max(left,right);
        
    }
    
    void find(TreeNode* root, int start, TreeNode* &BurnNode)
    {
        if(!root)
        return;
        
        if(root->val==start)
        {
            BurnNode= root;
            return;
        }
        
        find(root->left,start,BurnNode);
        find(root->right,start, BurnNode);
    }
    
    int Height(TreeNode* root)
    {
        if(!root)
        return 0;
        
        return 1+max(Height(root->left),Height(root->right));
    }
    

    
    int amountOfTime(TreeNode* root, int start) {
        int Timer=0;
        Burn(root,Timer,start);
        
        TreeNode *BurnNode= NULL;
        find(root,start,BurnNode);
        
        int high=Height(BurnNode)-1;
        
        return max(Timer,high);
    }
};