// 20 ms | 143.6 MB
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int>first;
        vector<int>between;
        vector<int>last;
        vector<int>ans;

        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<pivot)
            first.push_back(nums[i]);

            else if(nums[i]==pivot)
            between.push_back(nums[i]);

            else
            last.push_back(nums[i]);
        }

        int i=0;
        while(i<first.size())
        ans.push_back(first[i++]);

        i=0;
        while(i<between.size())
        ans.push_back(between[i++]);

        i=0;
        while(i<last.size())
        ans.push_back(last[i++]);

        return ans;


    }
};