class Solution {
public:
    int minChanges(string s) {
        int ans=0;
        for(int i=0;i+1<s.length();i++)
        {
            if(s[i]!=s[i+1] && i%2==0) 
            {
                ans++;
                s[i+1]=s[i];
            }
        }
        return ans;
        
    }
};