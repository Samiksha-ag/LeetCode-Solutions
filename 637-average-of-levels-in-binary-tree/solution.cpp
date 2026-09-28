// 0 ms | 23.9 MB
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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode* >q;
        q.push(root);
        vector<double>ans;

        while(!q.empty())
        {
            double sum=0;
            int n=q.size();
            int size=n;
            while(n--)
            {
                sum+=q.front()->val;
                TreeNode* temp=q.front();
                q.pop();

                if(temp->left)
                q.push(temp->left);

                if(temp->right)
                q.push(temp->right);

            }
            
            // we use size bcz n is decresing that's why we store initially the size to calculate avg.
            double avg= sum/size;
            ans.push_back(avg);

        }

        return ans;
    }
};