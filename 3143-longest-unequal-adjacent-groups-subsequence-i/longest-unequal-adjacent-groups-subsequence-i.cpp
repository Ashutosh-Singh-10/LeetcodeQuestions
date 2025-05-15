class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
            vector<string> ans;
        int prev=INT_MAX;
        for(int i=0;i<groups.size();i++)
        {
            if(groups[i]!=prev)
            {
                ans.push_back(words[i]);
            }
            prev=groups[i];
        }
        return ans;
    }
};