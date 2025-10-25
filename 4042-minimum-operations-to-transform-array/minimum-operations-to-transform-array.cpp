#define ll long long 
class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2) {
        ll tar=nums2.back(),ans=1e9,tot=0;;
        for(int i=0;i<nums1.size();i++){
            ll a=nums1[i];
            ll b=nums2[i];
            ll c=min(a,b);
            b=max(a,b);
            a=c;
            tot+=abs(a-b);
            if(tar<a) ans=min(ans,a-tar);
            else if(tar>b) ans=min(ans,tar-b);
            else ans=0;
        }
        
        return ans+1+tot;
        
    }
};