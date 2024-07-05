
class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int n=nums.size();
        int ans=0;
        auto fun=[&](int ls,int rs)
        {
            
            vector<int> vec(n,0);
            int sum=0;
            for(int i=0;i<ls-1;i++)
            {
                sum+=nums[i];
            }
            for(int i=ls-1;i<n;i++)
            {
                sum+=nums[i];
                if(i)
                vec[i]=max(vec[i-1],sum);
                else vec[i]=sum;
                sum-=nums[i-ls+1];
            }
            sum=0;
            for(int i=n-1;i>n-rs;i--)
            {
                sum+=nums[i];
            }
            for(int i=n-rs;i>=0;i--)
            {
                sum+=nums[i];
                if(i)
                {
                    ans=max(vec[i-1]+sum,ans);
                }
                else ans=max(ans,sum);
                sum-=nums[i+rs-1];
            }            
        };
        fun(firstLen,secondLen);
        fun(secondLen,firstLen);
        return ans;
        
    }
};