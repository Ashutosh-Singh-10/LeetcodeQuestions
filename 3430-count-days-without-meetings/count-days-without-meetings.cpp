class Solution {
public:
    int countDays(int days, vector<vector<int>>& vec) {
        sort(vec.begin(),vec.end());
        int prev=0;
        int ans=0;
        for(auto &i:vec)
        {
            auto s=i[0];auto e=i[1];
            if(s>prev)
            {
                ans+=max(0,min(s-prev-1,days-prev));

            }
            prev=max(prev,e);
        }
        ans+=max(0,days-prev);
        return ans;
        
    }
};