class Solution {
public:
    int minSwaps(vector<int>& nums, vector<int>& forbidden) {
        map<int,int> mp,tp;
        int n=nums.size(),cnt=0;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
            mp[forbidden[i]]++;
            if(nums[i]==forbidden[i]){
                tp[nums[i]]++;
                cnt++;
            }
        }
        for(auto &[a,b]:mp) if(b>n) return -1;
        int mx=0;
        for(auto &[a,b]:tp) mx=max(mx,b);
        return max((cnt+1)/2,mx);


        
        
    }
};

















