// 28 ms | 139.1 MB
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        deque<int>d;
        vector<int>ans;

        // traverse k-1 elements
        for(int i=0;i<k-1;i++)
        {
            if(d.empty())
            d.push_back(i);
            else
            {
                while(!d.empty() && nums[i]>nums[d.back()])
                d.pop_back();

                d.push_back(i);
            }
        }

        for(int i=k-1;i<n;i++)
        {
            // Remove smaller element from back
            while(!d.empty()&&nums[i]>nums[d.back()])
            d.pop_back();

            d.push_back(i);

            // if front is outside the window pop it
            if(d.front()<=i-k)
            d.pop_front();

            ans.push_back(nums[d.front()]);

        }

        return ans;
    }
};