class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long ans=0;
        long long mx=nums.back();
        while(nums.size()){
            long long x=nums.back();
            nums.pop_back();
            if(x<=mx) {
                mx=x;
            }
            else {
                long long tm=x/mx;
                if(x%mx) tm++;
                ans+=tm-1;
                mx=x/tm;

            }
        }
        return ans;
        
    }
};