class Solution {
public:
    
    int minDifference(vector<int>& nums) {
        if(nums.size()<=4) return 0;
        int diff=0;
        
        if(nums.size()==5)
        {
            diff=INT_MAX;
                sort(nums.begin(),nums.end());
            for(int i=1;i<5;i++)
            {
               diff=min(diff,nums[i]-nums[i-1]);
            }
    
            return diff;
        }
        priority_queue<int,vector<int>,greater<int>> pq1;
        priority_queue<int> pq2;    
        for(const auto &i:nums)
        {
            if(pq1.size()<4)
            {
                pq1.push(i);
            }
            else if(pq1.top()<i)
            {
                pq1.pop();
                pq1.push(i);
            }
            
            if(pq2.size()<4)
            {
                pq2.push(i);
            }
            else if(pq2.top()>i)
            {
                pq2.pop();
                pq2.push(i);
            }
            
        }
  
        vector<int> v1(4,0);
        vector<int> v2(4,0);
        while(pq1.size())
        {
            v1[pq1.size()-1]=pq1.top();
            pq1.pop();
        }
        while(pq2.size())
        {
            v2[pq2.size()-1]=pq2.top();
            pq2.pop();
        }
        int ans=INT_MAX;
        for(int i=0;i<4;i++)
        {
            ans=min(ans,v1[i]-v2[3-i]);
        }
        return ans;
        

        
    }
};