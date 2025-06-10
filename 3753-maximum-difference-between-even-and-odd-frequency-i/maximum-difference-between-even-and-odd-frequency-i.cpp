class Solution {
public:
    int maxDifference(string s) {
        map<int,int> mp;
        for(auto &i:s) mp[i]++;
        int mx=0,mn=1e8,ans=-1e8;
        for(auto &[a,b]:mp)
        {
            if(b%2==0) {
                mx=max(mx,b);
                mn=min(mn,b);
            }
        }
        for(auto &[a,b]:mp)
        {
            if(b%2)
            {
                ans=max(ans,b-mx);
                ans=max(ans,b-mn);
            }
        }
        return ans;
        
    }
};