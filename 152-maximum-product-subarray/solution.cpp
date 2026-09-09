// 0 ms | 17.9 MB
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi=INT_MIN;
        int Product=1;
        int negativeProduct=1;

        for(int i=0;i<nums.size();i++)
        {
            if(nums.size()==1)
            maxi=nums[i];

            Product*=nums[i];
            negativeProduct*=nums[nums.size()-1-i];

            maxi=max(maxi,Product);
            maxi=max(maxi,negativeProduct);

            if(Product==0)
            Product=1;

            if(negativeProduct==0)
            negativeProduct=1;


            
        }

        return maxi;
    }
};