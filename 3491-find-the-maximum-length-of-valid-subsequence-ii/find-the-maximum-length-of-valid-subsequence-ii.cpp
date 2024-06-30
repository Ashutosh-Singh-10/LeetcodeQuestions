class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n=nums.size();
        vector<unordered_map<int,int>> vec(n);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                int a=nums[i],b=nums[j];
                vec[i][(a+b)%k]=vec[j][(a+b)%k]+1;
                ans=max(vec[i][(a+b)%k],ans);
            }
            
        }
        return ans+1;
    

        
    }
};