// 3 ms | 22.9 MB
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
    TreeNode* arraytobst(vector<int>& nums,int start, int end)
    {
        if(start>end)
        return nullptr;

        int mid=start+(end-start)/2;
        
        TreeNode* temp=new TreeNode(nums[mid]);
        
        // left side
        temp->left=arraytobst(nums,start,mid-1);
        // right side
        temp->right=arraytobst(nums,mid+1,end);

        return temp;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
       
        return arraytobst(nums,0,nums.size()-1);
        
    }
};