class Solution {
public:
    int minSteps(int n) {
        int x=0;
        int ans=0;
        for(int i=2;i<=n;i++)
        {
            while(n%i==0)
            {
                n/=i;
                ans+=i;
            }
        }
        return ans;
        
    }
};