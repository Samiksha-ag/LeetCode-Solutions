// 40 ms | 45.3 MB
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        // initialize with 0,1
        m[0]=1;
        int prefixsum=0;
        int total=0;

        for(int i=0;i<nums.size();i++)
        {
            prefixsum+=nums[i];
            if(m.count(prefixsum-k))
            {
                total+=m[prefixsum-k];
                m[prefixsum]++;
            }

            else
            m[prefixsum]++;
        }

        return total;
    }
};