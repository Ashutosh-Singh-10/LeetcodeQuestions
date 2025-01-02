class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        map<int,int> mp;
        set<int> st={'a','e','i','o','u'};
        int cnt=0;
        for(int i=0;i<words.size();i++)
        {
            if(st.count(words[i][0]) && st.count(words[i].back())) cnt++;
            mp[i]=cnt;
        }
        mp[-1]=0;
        vector<int> ans;
        for(auto &i:queries)
        {
            ans.push_back(mp[i[1]]-mp[i[0]-1]);
        }
        return ans;
     
        
    }
};