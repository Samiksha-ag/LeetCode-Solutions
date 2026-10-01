// 7 ms | 27 MB
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

    int Find(int *in, int target,int start,int end)
    {
        for(int i=start;i<=end;i++)
        {
            if(in[i]==target)
            return i;
        }
        
        return -1;
    }
    
    TreeNode *Tree(int *in, int*pre, int Instart, int Inend, int index)
    {
        if(Instart>Inend)
        return NULL;
        
        TreeNode* root=new TreeNode(pre[index]);
        int pos=Find(in,pre[index], Instart, Inend);
        
        root->left=Tree(in,pre,Instart,pos-1,index+1);
        root->right=Tree(in,pre,pos+1,Inend, index+(pos-Instart)+1);
        
        return root;
        
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();

       return Tree(inorder.data(), preorder.data(), 0, n-1, 0);
    }
};