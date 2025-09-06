#define ll long long
class Solution {
public:
    long long minOperations(vector<vector<int>>& queries) {
        
        ll ans=0;
        for(auto &j:queries) 
        {
            ll l=j[0],r=j[1];
            ll tmp=0;
            for(ll i=0;i<=32;i+=2)
            {
                ll low=1ll<<i;
                ll high=(1ll<<(i+2))-1;
                ll start=max(l,low);
                ll end=min(r,high);
                if(end>=start)
                {
                    ll dif=end-start+1;
                    tmp+=dif*(i/2ll+1ll);
                }
                
            }
            ans+=(tmp+1ll)/2ll;
            
        }
        return ans;
    }
};