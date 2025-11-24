class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> ans;
        int number=0;
        for(auto &i:nums)
        {
            number*=2;
            number+=i;
            number%=10;
            if(number%5==0) ans.push_back(1) ;
            else ans.push_back(0);
          
        }
        return ans;
    }
};