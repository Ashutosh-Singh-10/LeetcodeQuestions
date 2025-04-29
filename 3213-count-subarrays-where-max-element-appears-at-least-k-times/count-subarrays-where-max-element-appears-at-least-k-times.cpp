#define ll long long
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long mx=*max_element(nums.begin(),nums.end());
        ll start=0;
        ll cnt=0;
        ll ans=0;
        for(ll i=0;i<nums.size();i++)
        {
            if(nums[i]==mx)
            {
                cnt++;

            }
            while(cnt>=k)
            {
                if(nums[start]==mx) cnt--;
                start++;

            }
            ans+=i-start+1;
        }
        
        return ((ll)(nums.size()+1)*(ll)nums.size())/2-ans;
        
    }
};