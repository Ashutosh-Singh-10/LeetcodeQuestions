class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int ones=count(nums.begin(),nums.end(),1);
        int zero=count(nums.begin(),nums.begin()+ones,0);
        int cnt=count(nums.begin(),nums.begin()+ones,1);
        int n=nums.size();
        int idx=ones%n,ans=zero;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0) zero--;else cnt--;
            if(nums[idx]==0) zero++;else cnt++;
            idx=(idx+1)%n;
            ans=min(ans,zero);
        }
        return ans;
        
        
        
    }
};