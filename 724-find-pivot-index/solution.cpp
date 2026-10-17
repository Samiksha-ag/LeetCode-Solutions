// 0 ms | 35.7 MB
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        long long totalsum=0;
        int index=-1;
        long long sum=0;

        if(n==1)
        return 0;

        for(int i=0;i<n;i++)
        totalsum+=nums[i];

        for(int i=0;i<n;i++)
        {
            
            if(totalsum-sum-nums[i]==sum)
            {
              index=i;
              break;
            }
            sum+=nums[i];
            
        }

        return index;
    }
};