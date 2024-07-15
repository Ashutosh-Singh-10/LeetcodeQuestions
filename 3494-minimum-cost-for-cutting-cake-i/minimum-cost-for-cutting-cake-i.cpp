#define ll long long
class Solution {
public:
    long long minimumCost(int m, int n, vector<int>& hc, vector<int>& vc) {
        vector<pair<int,int>> vec;
        for(auto &i:hc)
        {
            vec.push_back({i,0});
        }
        for(auto &i:vc)
        {
            vec.push_back({i,1});
        }
        ll c=1,r=1;
        sort(vec.begin(),vec.end(),greater<pair<int,int>>());
        ll ans=0;
        for(auto &[a,b]:vec)
        {
            if(b==0)
            {
                ans+=a*(r);
                c++;
                
            }
            else 
            {
                ans+=a*(c);
                r++;
            }
        }
        
        return ans;
    }
};