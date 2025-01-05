class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n=s.length();
        vector<int> vec(n+1,0);
        for(auto &i:shifts)
        {
            vec[i[0]]+=2*i[2]-1;
            vec[i[1]+1]-=2*i[2]-1;
        }
        int cnt=0;
        string ans;
        for(int i=0;i<n;i++)
        {
            cnt+=vec[i];
            int ch='a'+(((s[i]-'a'+cnt)%26+26)%26);
            ans.push_back(ch);
        }
        return ans;
        
        
    }
};