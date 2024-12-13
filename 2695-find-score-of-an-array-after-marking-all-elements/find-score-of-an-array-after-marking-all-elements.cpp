class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n=nums.size();
        set<pair<int,int>> st;
        for(int i=0;i<n;i++)
        {
            st.insert({nums[i],i});
        }
        long long ans=0;
        while(st.size())
        {
            auto [a,b]=*st.begin();
            ans+=a;
            if(b>0 && st.count({nums[b-1],b-1}))
            {
                st.erase(st.find({nums[b-1],b-1}));
            }
            if(b<n-1 && st.count({nums[b+1],b+1}))
            {
                st.erase(st.find({nums[b+1],b+1}));
            }
            st.erase(st.begin());
        }
        return ans;
        
    }
};