class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        long long ans,l=0,h=1e9,mid;
        long long n=nums.size();
        while(l<=h)
        {
            mid=l+(h-l)/2ll;
            long long tmp=0;
            for(int i=0;i<n;i++)
            {
                if(nums[i]<=mid)
                {
                    tmp++;
                    i++;
                }
            }
            if(tmp>=k)
            {
                ans=min(ans,mid);
                h=mid-1;
            }
            else l=mid+1;
            // cout<<l<< " "<<h<<" "<<mid<<endl;
        }
        return ans;
        
    }
};