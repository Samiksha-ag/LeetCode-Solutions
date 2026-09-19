// 3 ms | 9.8 MB
class Solution {
public:
    bool isPalindrome(string s) {
    
        int first=0,second=s.size()-1;
        
        while(first<second)
        {
            // this will skip spaces,commas,etc.etc.
            while(first<second && !isalnum(s[first]))
            {
                first++;
            }
            // we use while loop here bcz it will check multiple time and if we use if then it will check only one time.
            while(first<second && !isalnum(s[second]))
            {
                second--;
            }

            if(tolower(s[first])!=tolower(s[second]))
            return 0;

            first++,second--;
        }

        return 1;
    }
};