class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> cnt(n+1,0);
        int cur=0,ans=0;;
        for(int i=0;i<n;i++)
        {
            cur+=cnt[i];
            if(cur%2==0 && nums[i]==0)
            {
                if(i+k>n) return -1;
                cnt[i+k]=1;
                cur++;
                ans++;
            } 
            else if(cur%2 && nums[i])
            {
                if(i+k>n) return -1;
                cnt[i+k]=1;
                cur++;
                ans++;
            }
            
        }
        return ans;
        
        
    }
};