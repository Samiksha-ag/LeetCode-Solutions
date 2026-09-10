// 2 ms | 7.8 MB
class Solution {
public:
    string defangIPaddr(string address) {
        int index=0;
        string ans;

        while(index<address.size())
        {
            if(address[index]=='.')
            ans+="[.]";

            else
            ans+=address[index];

            index++;
        }

        return ans;
    }
};