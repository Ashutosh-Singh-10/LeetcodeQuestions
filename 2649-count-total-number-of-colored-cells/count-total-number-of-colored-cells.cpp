class Solution {
public:
    long long coloredCells(int n) {
        long long ans=1,x=4;
        for(int i=1;i<n;i++)
        {
            ans+=x;
            x+=4;
        }
        return ans;
        
    }
};