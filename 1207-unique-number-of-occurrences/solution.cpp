// 0 ms | 12.1 MB
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> freq;
        
        // Count frequency of each number
        for(int x : arr) {
            freq[x]++;
        }
        
        // Store frequencies to check duplicates
        unordered_set<int> seen;
        
        for(auto it : freq) {
            if(seen.count(it.second)) {
                return false;
            }
            seen.insert(it.second);
        }
        
        return true;
    }
};