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

    TreeNode *Tree(int *in, int*post, int Instart, int Inend, int index)
    {
        if(Instart>Inend)
        return NULL;
        
        TreeNode* root=new TreeNode(post[index]);
        int pos=Find(in,post[index], Instart, Inend);
        
        //Right
        root->right=Tree(in,post,pos+1,Inend, index-1);
        //Left
        root->left=Tree(in,post,Instart,pos-1,index-(Inend-pos)-1);
        
        
        return root;
        
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();

        return Tree(inorder.data(), postorder.data(), 0, n-1, n-1);
    }
};