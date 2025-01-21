class Solution {
public:
    int compress(vector<char>& chars) {
        string ans;
        int prev=chars[0];
        int cnt=0;
        for(auto &ch:chars)
        {
            if(ch==prev) 
            {
                cnt++;
            }
            else 
            {
                ans.push_back(prev);
                if(cnt>1)
                {
                    ans+=to_string(cnt);
                }
                cnt=1;
                prev=ch;
            }
        }
        ans.push_back(prev);
        if(cnt>1)
        {
            ans+=to_string(cnt);
        }
        for(int i=0;i<ans.length();i++) 
        {
            chars[i]=ans[i];
        }
        return ans.length();
        
    }
};