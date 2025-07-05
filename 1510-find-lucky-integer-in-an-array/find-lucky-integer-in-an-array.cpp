class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int> mp;
        for(auto &i:arr) mp[i]++;
        int ans=-1;
        for(auto &[a,b]:mp)
        {
            if(a==b) ans=max(ans,a);
        }
        return ans;
        
    }
};