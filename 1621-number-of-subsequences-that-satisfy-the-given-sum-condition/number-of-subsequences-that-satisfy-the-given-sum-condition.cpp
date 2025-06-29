int mod=1e9+7;
int pow(int x,int p)
{
    if(p==0) return 1;
    if(p==1) return x;
    long long tmp=pow(x,p/2);
    tmp=(tmp*tmp)%mod;
    if(p%2)
    {
        tmp=(tmp*x)%mod;
    }
    return tmp;
}
class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int l=0,r=n-1;
        int ans=0;
        while(l<n)
        {
            while(l<=r && nums[l]+nums[r]>target )
            {
                r--;
            }
            if(r<l) break;
            ans=(ans+pow(2,r-l))%mod;
            l++;
        }
        return ans;
        
    }
};