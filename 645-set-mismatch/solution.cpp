// 1 ms | 26.1 MB
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        vector<int> freq(n + 1, 0);

        for(int i = 0; i < n; i++)
        freq[nums[i]]++;
        
        // check duplicate
        for(int i = 1; i <= n; i++)
        {
            if(freq[i] == 2)
            ans.push_back(i);
        }
        
        // check missing
        for(int i = 1; i <= n; i++)
        {
            if(freq[i] == 0)
            ans.push_back(i);
        }

        return ans;

    }
};