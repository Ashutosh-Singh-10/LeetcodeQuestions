class Solution {
public:
    bool possible(vector<int> &nums,int x,int p)
    {
        int count=0;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]-nums[i-1]<=x)
            {
                count++;
                i++;
            }
            if(count>=p) return 1;
        }
        return 0;
    }
    int minimizeMax(vector<int>& nums, int p) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int mx=nums[n-1]-nums[0];
        int mn=0;
        int mid;

        while(mx>mn)
        {
            mid=mn+(mx-mn)/2;
            if(possible(nums,mid,p))
            {
                mx=mid;
            }
            else
            {
                mn=mid+1;
            }
        }
        mid=mn+(mx-mn)/2;
        return mid;






        
    }
};