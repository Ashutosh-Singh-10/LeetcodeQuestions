#define ll long long 
ll mod=1e9+7;
class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
     
        map<long long , long long>mp;
        for(auto &i:points)
        {
             mp[i[1]]++;
        }
        ll ans=0,cnt=0;
        for(auto &[a,b]:mp)
        {
            ll tmp=((b*(b-1))/2ll)%mod;
            
            
            ans=(ans+(cnt*tmp))%mod;
            cnt+=tmp;
            
        }

        
        return ans;
    }

};