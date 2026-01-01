#define ll long long
class Solution {
public:
    long long maximumScore(vector<int>& nums) {
        multiset<ll> st;
        for(auto &i:nums) st.insert(i);
        ll sum=0,ans=-1e18;
        nums.pop_back();
        for(auto &i:nums){
            sum+=i;
            st.erase(st.find(i));
            ans=max(ans,sum-*st.begin());
        }
        return ans;
        
    }
};