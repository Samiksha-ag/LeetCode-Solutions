// 17 ms | 144.9 MB
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>positive;
        vector<int>negative;
        vector<int>ans;
        
        // store negative and positive separately.
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>=0)
            positive.push_back(nums[i]);
            else
            negative.push_back(nums[i]);
        }

        // first pointer will indicate +ve array.
        // second will indicate -ve array.
        int first=0,second=0;

        while(first<positive.size() && second<negative.size())
        {
            ans.push_back(positive[first]);
            first++;
            ans.push_back(negative[second]);
            second++;
        }
        
        // if one of them is not empty.
        while(first<positive.size() )
        ans.push_back(positive[first++]);

        while(second<negative.size())
        ans.push_back(negative[second++]);

        return ans;
    }
};