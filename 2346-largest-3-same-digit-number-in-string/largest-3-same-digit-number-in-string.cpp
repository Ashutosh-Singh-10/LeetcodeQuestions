class Solution {
public:
    string largestGoodInteger(string s) {
        string ans="";
        for(int i=0;i<s.size()-2;i++)
        {
            if(s[i]==s[i+1] && s[i]==s[i+2])
            {
                ans=max(ans,s.substr(i,3));

            }
            
        }
        return ans;
        
    }
};