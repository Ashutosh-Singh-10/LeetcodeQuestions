class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& vec, vector<int>& queries) {
        sort(vec.begin(),vec.end(),[&](vector<int> a,vector<int> b) {
            return a[0]<b[0];
        });
        int mx=0;
        map<int,int> mp;
        mp[0]=0;
        for(int i=0;i<vec.size();i++)
        {
            mx=max(mx,vec[i][1]);
            mp[vec[i][0]]=mx;
        }
        vector<int> ans;
        for(int i=0;i<queries.size();i++)
        {
            auto it=mp.upper_bound(queries[i]);
            it--;
            ans.push_back(it->second);

        }
        return ans;
        
        
    }
};