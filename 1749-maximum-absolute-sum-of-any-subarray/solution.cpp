// 0 ms | 45.2 MB
class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxi=0;
        int prefix=0;
        int negativeprefix=0;

        for(int i=0;i<nums.size();i++)
        {
            prefix+=nums[i];
            negativeprefix+=nums[i];

            maxi=max(maxi,prefix);
            maxi=max(maxi,abs(negativeprefix));

            if(prefix < 0)
            prefix = 0;

            if(negativeprefix > 0)
            negativeprefix = 0;
        }

        return maxi;
        
    }
};