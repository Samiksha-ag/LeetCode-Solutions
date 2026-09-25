// 0 ms | 15.1 MB
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL)
        return ans;

        stack<TreeNode*>s1; //Left to Right
        stack<TreeNode*>s2;  //Right to left

        s1.push(root);
       

        while(!s1.empty()||!s2.empty())
        {
            vector<int>ans1;
            // Left to right
            if(!s1.empty())
            {
                while(!s1.empty())
                {
                    TreeNode* temp=s1.top();
                    s1.pop();
                    ans1.push_back(temp->val);
                    if(temp->left)
                    s2.push(temp->left);
                    if(temp->right)
                    s2.push(temp->right);
                }
            }

            
            // Right to left
            else
            {
                while(!s2.empty())
                {
                    TreeNode* temp=s2.top();
                    s2.pop();
                    ans1.push_back(temp->val);
                    if(temp->right)
                    s1.push(temp->right);
                    if(temp->left)
                    s1.push(temp->left);
                }

            }
            ans.push_back(ans1);


        }

        return ans;

    }
};