class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int a=0,b=0;
        int ans=0;
        int c1=0;
        int c2=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]%2) 
            {
                c1++;
                c2++;
            }
            while(c1>k)
            {
                if(nums[a]%2) c1--;
                a++;

            }
            while(c2>=k)
            {
                if(nums[b]%2) c2--;
                b++;

            }
            ans+=b-a;

        }
        return ans;
        
    }
};