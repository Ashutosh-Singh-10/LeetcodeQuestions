class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        vector<pair<int,int>> vec;
        for(auto &i:events) vec.push_back({i[1],i[0]});
        sort(vec.begin(),vec.end());
        set<int> st;
        for(int i=0;i<=1e5+1;i++)
        {
            st.insert(i);

        }
        int free=0,ans=0;
        for(auto &[b,a]:vec)
        {
            auto it=st.lower_bound(a);
            if(*it>b) continue;
            ans++;
            st.erase(it);
        }
       
        return ans;
        
    }
};