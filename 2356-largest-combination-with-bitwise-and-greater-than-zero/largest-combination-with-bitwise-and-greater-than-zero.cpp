class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int> vec(32,0);
        for(auto &el:candidates)
        {
            for(int i=0;i<=31;i++)
            {
                if(el&1) vec[i]++;
                el>>=1;
            }
        }
        int ans=1;
        for(auto &i:vec) ans=max(ans,i);
        return ans;
        
    }
};