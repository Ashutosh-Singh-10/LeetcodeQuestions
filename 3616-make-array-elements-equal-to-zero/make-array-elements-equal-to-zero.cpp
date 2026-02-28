class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int sum=0;
        for(auto &i:nums) sum+=i;
        if(sum==0) return 2*nums.size();
        int ans=0;
        int x=0;
        for(auto &i:nums){
            sum-=i;
            x+=i;
            if(x==sum && i==0) ans+=2;
            else if(abs(x-sum)<=1 && i==0) ans++; 
        }
        return ans;
        
    }
};