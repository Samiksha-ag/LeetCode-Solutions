// 0 ms | 12.4 MB
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool>ans;
        
        // calculate maximum
        int maxi = candies[0];

        for(int i = 1; i < candies.size(); i++)
        {
           if(candies[i] > maxi)
           maxi = candies[i];
        }
        
        // check for each candy
        for(int i = 0; i < candies.size(); i++)
        {
            if(candies[i] + extraCandies >= maxi)
            ans.push_back(true);
            else
            ans.push_back(false);
        }

        return ans;

    }
};