class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int p=0,n=0,ans=0;
        for(auto &i:nums)
        {
            p+=i;
            n+=i;
            if(p<0) p=0;
            if(n>0) n=0;
            ans=max({ans,abs(n),p});
        }
        return ans;
        
    }
};