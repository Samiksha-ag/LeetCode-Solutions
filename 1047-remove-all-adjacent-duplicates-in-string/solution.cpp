// 6 ms | 14.4 MB
class Solution {
public:
    string removeDuplicates(string s) {
        stack<char>st;
        string ans="";

        for(int i=0;i<s.size();i++)
        {
            if(st.empty())
            st.push(s[i]);

            else if(st.top()==s[i])
            st.pop();

            else
            st.push(s[i]);
        }

        int i=0;
        while(!st.empty())
        {
            ans+=st.top();
            i++;
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;


    }
};