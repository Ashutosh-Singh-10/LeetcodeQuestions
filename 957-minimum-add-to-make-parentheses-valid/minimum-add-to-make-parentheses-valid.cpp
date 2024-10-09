class Solution {
public:
    int minAddToMakeValid(string s) {
        int cnt=0;
        int ans=0;
        for(auto &i:s)
        {
            if(i=='(') cnt++;
            else if(i==')') cnt--;
            if(cnt<0)
            {
                cnt=0;ans++;
            }
        }
        reverse(s.begin(),s.end());
        cnt=0;
        for(auto &i:s)
        {
            if(i=='(') cnt--;
            else if(i==')') cnt++;
            if(cnt<0)
            {
                cnt=0;ans++;
            }
        }
        return ans;
        
    }
};