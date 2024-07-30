class Solution {
public:
    int minimumDeletions(string s) {
        int a=count(s.begin(),s.end(),'a');
        int ans=min(a,(int)s.length()-a);
        int b=0;
        for(auto &i:s)
        {
            if(i=='b') b++;
            else a--;
            ans=min(ans,b+a);
        }
        return ans;
        
    }
};