class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> cnt(200,0);
        vector<int> cur(200,0);
        for(auto &i:s) cnt[i]++;
        int x=0,sz=0;
        vector<int> ans;
        for(auto &i:s)
        {
            cur[i]++;
            if(cur[i]==1)
            {
                x++;
            }
            if(cur[i]==cnt[i])
            {
                x--;
            }
            sz++;
            if(x==0)
            {
                ans.push_back(sz);
                sz=0;
            }
           
            
            
            

        }
        if(sz>0)
        ans.push_back(sz);
        return ans;

        
    }
};