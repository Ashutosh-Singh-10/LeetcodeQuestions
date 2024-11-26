class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> vec(n,0);
        for(auto &i:edges)
        {
            vec[i[1]]++;
            
        }
        int ans=0;
        int win;
        for(int i=0;i<n;i++)
        {
            if(vec[i]==0)
            {
                ans++;
                win=i;
            }
        }
        // for(auto &i:vec)cout<<i<<"  ";
        // cout<<endl;
        if(ans==1) return win;
        return -1;
        
    }
};