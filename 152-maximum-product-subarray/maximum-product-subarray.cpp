class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int neg=1;
        int prod=1;
        int ans=INT_MIN;
        for(auto &i:nums)
        {
            prod*=i;
            ans=max(prod,ans);
            ans=max(prod/neg,ans);
            if(prod<0 && neg==1)
            {
                neg=prod;
            }
            if(prod==0)
            {
                prod=1;
                neg=1;
            }
        }
        return ans;
    }
};