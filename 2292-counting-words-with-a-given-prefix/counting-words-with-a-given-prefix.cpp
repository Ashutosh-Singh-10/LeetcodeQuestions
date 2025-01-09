class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int ans=0;
        for(auto &i:words)
        {
            if(i.size()>=pref.size() && i.substr(0,pref.size())==pref) ans++;

        }
        return ans;
        
    }
};