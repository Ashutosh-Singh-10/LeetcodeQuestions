class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prev=0;
        int ans=0;
        int x=0;
        for(auto &i:bank)
        {
            x=0;
            for(auto &j:i)
            {
                if(j=='1')
                {
                    x++;
                }
            }
            ans+=prev*x;
            if(x)
            {
                prev=x;
                
            }
        }
        return ans;
        
    }
};