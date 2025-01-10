class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> cnt(26,0);
        vector<string> ans;
        for(auto &i:words2)
        {
            map<int,int> mp;
            for(auto &j:i) mp[j-'a']++;
            for(auto &[a,b]:mp) cnt[a]=max(b,cnt[a]);
        }
        for(auto &i:words1)
        {
            map<int,int> mp;
            for(auto &j:i) mp[j-'a']++;
            int bit=1;
            for(int i=0;i<26;i++) 
            {
                if(cnt[i]>mp[i]) 
                {
                    bit=0;
                    break;
                }

            }
            if(bit) ans.push_back(i);


        }
        return ans;

        
       

        
    }
};