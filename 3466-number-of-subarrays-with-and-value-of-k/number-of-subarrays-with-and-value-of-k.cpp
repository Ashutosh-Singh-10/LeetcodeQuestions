#define ll long long
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        map<ll ,ll> mp;
        ll ans=0;
        for(auto &i:nums)
        {
            map<ll,ll> tp;
            tp[(ll)i]=1;
            for(auto &[a,b]:mp)
            {
                tp[(ll)a & (ll)i]+=b;
            }
            mp=tp;;
            ans+=mp[k];
        }
        return ans;
        
    }
};