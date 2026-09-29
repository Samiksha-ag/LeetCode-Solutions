// 0 ms | 13.9 MB
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
       int maxi=0;
       for(int i=0;i<nums.size();i++)
       {
          if(nums[i]>nums[maxi])
          maxi=i;
       }

        for (int i = 0; i < nums.size(); i++) 
        {
           if (i != maxi && nums[maxi] < 2 * nums[i])
           return -1;
        }

        return maxi;


    }
};