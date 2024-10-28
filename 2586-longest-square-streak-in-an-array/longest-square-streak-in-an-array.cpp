class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_set<long long> u_set;
        for(auto& i:nums)
        {
            if(!u_set.count(i)) u_set.insert(i);
        }
        int count;
         long long int i;
        int ans=0;
        for(auto j:u_set)
        {
            
            i=j;
            count=1;
            while(u_set.count(i*i))
            {
                count++;
                i=i*i;
            }
            if(count>ans) ans=count;
        }
        if(ans==1) return -1;
        return ans;
        
        
        
    }
};