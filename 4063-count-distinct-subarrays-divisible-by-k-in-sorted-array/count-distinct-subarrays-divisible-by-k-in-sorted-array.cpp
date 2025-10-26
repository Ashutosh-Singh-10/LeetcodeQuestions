class Solution {
public:
    long long numGoodSubarrays(vector<int>& nums, int k,int flag=1) {
        long long ans=0;
        map<long long,long long> mp;
        mp[0]=1;
        long long mod=0;
        for(auto &i:nums) {
            mod=(mod+i)%k;
            ans+=mp[mod];
            mp[mod]++;
        }
        if(flag==0) return ans;
        vector<vector<int>> vec;
        for(auto &i:nums){
            if(vec.size()==0) {
                vec.push_back({i});
            }
            else if(i==vec.back().back()){
                vec.back().push_back(i);
            }
            else vec.push_back({i});
        }
        for(auto &i:vec) {
            long long x=numGoodSubarrays(i,k,0);
            long long el=i[0];
            if(x>=1){
                long long lcm=(el*(long long)k)/__gcd(el,(long long)k);
                long long sum=el*i.size();
                long long tot=sum/lcm;
                if(tot>1) ans+=tot-1;
            }
            if(x>1) ans-=x-1;
        }
        return ans;
        
    }
};