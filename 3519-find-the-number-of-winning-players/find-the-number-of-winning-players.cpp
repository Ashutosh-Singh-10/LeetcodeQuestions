class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        map<int,map<int,int>> mp;
        int ans=0;
        for(auto i:pick)
        {
            int a=i[0],b=i[1];
            mp[a][b]++;
        }
        for(auto &[a,b]:mp)
        {
            for(auto &[d,c]:b) if(c>a) {ans++;break;}
        }
        return ans;
        
    }
};