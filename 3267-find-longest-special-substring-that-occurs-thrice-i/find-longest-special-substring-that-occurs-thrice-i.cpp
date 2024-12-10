class Solution {
public:
    int maximumLength(string s) {
        int n=s.length();
        map<string,int> mp;
        for(int i=0;i<n;i++)
        {
            string t;
            for(int j=i;j<n;j++)
            {
                if(t.size()!=0 && t[0]!=s[j]) break;
                t.push_back(s[j]);
                
                mp[t]++;

            }
        }
        int ans=0;
        for(auto [a,b]:mp)
        {
            if(b>=3) ans=max(ans,(int)a.length());
        }
        return ans==0?-1:ans;
        
    }
};