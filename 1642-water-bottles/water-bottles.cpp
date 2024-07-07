class Solution {
public:
    int numWaterBottles(int n, int e) {
        int ans=0;
        int l=0;
        while(n)
        {
            ans+=n;
            l+=n;
            n=l/e;
            l=l%e;
        }
        return ans;
        

        
    }
};