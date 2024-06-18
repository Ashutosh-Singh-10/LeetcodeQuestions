class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n=profit.size();
        vector<pair<int,int>> vec;
        for(int i=0;i<n;i++)
        {
            vec.push_back({difficulty[i],profit[i]});
        }
        sort(vec.begin(),vec.end());
        map<int,int> mp;
        int mx=0;
        for(auto &i:vec)
        {
            if(i.second>mx)
            {
                mx=i.second;
                mp[i.first]=i.second;
            }
        }
        int ans=0;
        for(auto &i:worker)
        {
            auto it=mp.upper_bound(i);
            if(it!=mp.begin())
            {
                it--;
                ans+=it->second;
            }
        }
        return ans;


        
    }
};