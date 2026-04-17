class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        map<int,int> mp;
        int n=nums.size();
        int ans=1e9;
        for(int i=n-1;i>=0;i--) {
            string s=to_string(nums[i]);
            reverse(s.begin(),s.end());
            int el=stoi(s);
            if(mp.count(el)){
                ans=min(ans,mp[el]-i);
            }
            mp[nums[i]]=i;
        }
        return ans==1e9?-1:ans;
        
        
    }
};