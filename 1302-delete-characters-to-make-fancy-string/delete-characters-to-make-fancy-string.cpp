class Solution {
public:
    string makeFancyString(string s) {
        if(s.length()<=2) return s;
        string ans=s.substr(0,2);
        for(int i=2;i<s.length();i++)
        {
            int x=ans.length();
            if(ans[x-1]==s[i] && ans[x-2]==s[i]) continue;
            ans.push_back(s[i]);
        }
        return ans;
        
    }
};