class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        int mod=1e9+7;
        map<int,int> a,b;
        int ans=0;
        for(auto &i:nums) {
            if(i%2==0){
                ans=(ans+b[i/2])%mod;
            }
            b[i]=(b[i]+a[i*2])%mod;
            a[i]++;
         
        }
        return ans;
        
    }
};