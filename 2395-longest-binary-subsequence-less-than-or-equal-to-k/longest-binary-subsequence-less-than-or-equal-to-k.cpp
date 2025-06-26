class Solution {
public:
    int sti(string s)
    {
        long long p=1,ans=0;
        while(s.size())
        {
            ans+=(s.back()-'0')*p;
            s.pop_back();
            p*=2ll;
        }
        return ans;
    }
    int longestSubsequence(string s, int k) {
        int ans=0;
        string t;
        int cnt=0;
        for(int i=0;i<s.length();i++)
        {
            t.push_back(s[i]);
            
            while(t[0]=='0')
            {
                t=t.substr(1);
                cnt++;
                
            }
            while(sti(t)>k)
            {
                if(t[0]=='0') cnt++;
                t=t.substr(1);
            }
            ans=max(ans,(int)t.length()+cnt);
        }
        return ans;
        
    }
};