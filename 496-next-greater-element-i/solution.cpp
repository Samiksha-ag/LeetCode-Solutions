// 1 ms | 12.2 MB
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int index;
        stack<int>st;
        vector<int>ans(nums1.size(),-1);
        for(int i=0;i<nums1.size();i++)
        {
            for(int j=0;j<nums2.size();j++)
            if(nums1[i]==nums2[j])
            {
                index = j;
                break;
            }

            for(int j=index+1;j<nums2.size();j++)
            {
            
                if(nums2[j] > nums1[i])
                {
                  ans[i] = nums2[j];
                  break;
                }
            }    

        }

        return ans;
    
    }
};