class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        multiset<int> a,b;
        int ans=0;
        for(auto &i:arrays)
        {
            int mx=INT_MIN,mn=INT_MAX;
            for(auto &j:i)
            {
                mx=max(j,mx);
                mn=min(j,mn);
            }
            a.insert(mn);
            b.insert(mx);
        }
        for(auto &i:arrays)
        {
            int mx=INT_MIN,mn=INT_MAX;
            for(auto &j:i)
            {
                mx=max(j,mx);
                mn=min(j,mn);
            }
            a.erase(a.find(mn));
            b.erase(b.find(mx));
            ans=max(abs(mx-*a.begin()),ans);
            ans=max(abs(*b.rbegin()-mn),ans);
            a.insert(mn);
            b.insert(mx);

        }
        return ans;

        
    }
};