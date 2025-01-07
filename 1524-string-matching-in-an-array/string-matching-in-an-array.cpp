class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        map<string,int> mp;
        for(auto &i:words)
        {
            for(int j=0;j<i.size();j++)
            {
                string t;
                for(int k=j;k<i.size();k++)
                {
                    t.push_back(i[k]);
                    mp[t]++;
                }
            }
        }
        vector<string> ans;
        for(auto &i:words) if(mp[i]>1) ans.push_back(i);

        return ans;
        
    }
};