class Solution {
public:
    int takeCharacters(string s, int k) {
        int x=0,y=0,z=0;
        for(auto &i:s) {
            if(i=='a') x++;
            else if(i=='b') y++;
            else z++;
        }
        if(x<k || y<k || z<k) return -1;
        int a=x,b=y,c=z;
        int idx=0;
        int ans=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='a') a--;
            else if(s[i]=='b') b--;
            else c--;
            while(a<k || b<k || c<k)
            {
                if(s[idx]=='a') a++;
                else if(s[idx]=='b') b++;
                else c++;
                idx++;

            }
            ans=max(ans,i-idx+1);
        }
        return s.length()-ans;

        
    }
};