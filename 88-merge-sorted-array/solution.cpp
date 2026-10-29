// 0 ms | 12.5 MB
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int first=0,second=0;
        vector<int>ans;
        
        
        while(first<m&& second<n)
        {
            
            if(nums1[first] <= nums2[second])
            {
                ans.push_back(nums1[first++]);
            }
            else
            {
                ans.push_back(nums2[second++]);
            }
        }
        
        while(first<m)
        ans.push_back(nums1[first++]);
        
        while(second<n)
        ans.push_back(nums2[second++]);

        nums1=ans;
        
    }
};