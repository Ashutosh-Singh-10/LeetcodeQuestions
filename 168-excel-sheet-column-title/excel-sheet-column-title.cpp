class Solution {
public:
    string convertToTitle(int x) {
        string ans;
        while(x>=1)
        {
            int mod=x%26;
            if(mod==0) mod=26;
            ans.push_back('A'+mod-1);
            if(mod==26) 
            x--;
            // break;
            x/=26;
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};