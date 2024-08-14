class Solution {
public:
    int check(vector<int> &nums,int mid)
    {
        int idx=0;
        int cnt=0;
        for(int i=0;i<nums.size();i++)
        {
            while(nums[i]-nums[idx]>mid)
            {
                idx++;
            }
            cnt+=i-idx;

        }
        return cnt;

    }
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int h=1e6,l=0,mid,ans=0;
        while(l<=h)
        {
            mid=l+(h-l)/2;
            if(check(nums,mid)>=k)
            {
                h=mid-1;
            }
            else 
            {
                l=mid+1;
                ans=l;
            }

        }
        return ans;

        
    }
};