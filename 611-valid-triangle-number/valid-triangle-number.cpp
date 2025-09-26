class Solution {
public:
    int triangleNumber(vector<int>& nums) 
    {
        if(nums.size()<3) return 0 ;
        sort(nums.begin(),nums.end());
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            int start=nums.size()-1;
            for(int j=nums.size()-1;j>i;j--)
            {
                while(start>=j || (start>i && nums[i]+nums[start]>nums[j]))
                {
                    start--;
                    
                }
                ans+=j-start-1;
                
            }

         
        }
        return ans;

        // 4 5 6 7 8 9 10
        

        
        
    }
};