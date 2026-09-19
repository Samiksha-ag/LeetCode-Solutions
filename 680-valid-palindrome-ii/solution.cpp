// 0 ms | 22.1 MB
class Solution {
public:
    bool check(string &s,int first,int second)
    {
        while(first<second)
        {
            if(s[first]!=s[second])
            return false;

            first++,second--;
        }

        return true;

    }
    bool validPalindrome(string s) {
        int first=0,second=s.size()-1;

        while(first<second)
        {
            if(s[first]==s[second])
            {
                first++,second--;

            }

            else
            {
               return check(s,first+1,second)||check(s,first,second-1);
            }

        }

        return true;
    }
};