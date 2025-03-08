class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n=blocks.size(),cnt=0;
        for(int i=0;i<k-1;i++) 
        {
            if(blocks[i]=='W') cnt++; 
        }
        int ans=n;
        for(int i=k-1;i<n;i++) 
        {
            if(blocks[i]=='W') cnt++;
            ans=min(ans,cnt);
            if(blocks[i-k+1]=='W') cnt--;
        }
        return ans;
        
    }
};