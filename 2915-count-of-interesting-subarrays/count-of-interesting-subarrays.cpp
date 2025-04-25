class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, long long modulo, long long k) {
        
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]%modulo==k) nums[i]=1;
            else nums[i]=0;
        }
        long long sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            nums[i]=sum;
        }
        // for(auto &i:nums) cout<<i;
        long long ans=0;
//         for(int i=0;i<nums.size();i++)
//         {
            
//             if(nums[i]%modulo==k  ) ans++;
//             for(int j=i+1;j<nums.size();j++)
//             {
//                 if((nums[j]-nums[i])%modulo==k ) ans++;
//             }
//         }
        unordered_map<long long, long long> mp;
        mp[0]=1;
        for(int i=0;i<nums.size();i++)
        {
            // ans+=mp[(nums[i]+k)%modulo];
            
                    ans+=(long long)mp[(nums[i]-k+modulo)%modulo];
                            mp[nums[i]%modulo]++;
                            
        }
        
        // cout<<endl;
        // for(auto &i:mp)
        // {
        //     cout<<i.first<<"  "<<i.second<<"      ";
        // }
        // cout<<endl;
        return ans;
        
    }
};