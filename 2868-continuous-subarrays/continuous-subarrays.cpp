class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        unordered_map<int,int> mp;
        int start=0,val,cnt,end;
        long long ans=0;
        for(int i=0;i<nums.size();i++)
        {
            end=i;
            val=nums[i];
            mp[val]++;
            cnt=mp[val+2]+mp[val+1]+mp[val]+mp[val-1]+mp[val-2];
            while(cnt!=end-start+1)
            {
                mp[nums[start]]--;
                start++;
                cnt=mp[val+2]+mp[val+1]+mp[val]+mp[val-1]+mp[val-2];
            }
            ans+=(end-start)+1;
          
            
        }
        return ans;
                
        
    }
};