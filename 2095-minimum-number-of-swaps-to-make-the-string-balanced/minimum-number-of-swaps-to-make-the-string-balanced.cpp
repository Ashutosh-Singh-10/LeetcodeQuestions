class Solution {
public:
    int minSwaps(string s) {
        int x=0;
        int cnt=0;
        int ans=0;
        for(auto &i:s)
        {
            if(i=='[') cnt++;
            else cnt--;
            if(cnt<0) 
            {
                cnt=0;
                ans++;
            }
        }
        return (ans+1)/2;
        
        
        
    }
};