class Solution {
public:
    int maxScore(string s) {
        int x=0,y=0,ans=0;


        for(auto &i:s)
        {
            if(i=='1') x++;
        }

        for(int k=0;k<s.length()-1;k++)
        {
            char i=s[k];
            if(i=='1') x--;
            else y++;
            ans=max(ans,x+y);
        }
        return ans;
    
        
    }
};