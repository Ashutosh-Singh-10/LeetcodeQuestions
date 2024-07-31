class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n=books.size();
        vector<long long> dp(n+1,INT_MAX);
        dp[0]=0;
        int mx,w;
        dp[1]=books[0][1];
        for(int i=2;i<n+1;i++)
        {
            int h=books[i-1][1],w=books[i-1][0];
            dp[i]=dp[i-1]+h;
            for(int j=i-1;j>0;j--)
            {
                if(books[j-1][0]+w>shelfWidth)break;

                 h=max(h,books[j-1][1]);   
                 w+=books[j-1][0];
                 dp[i]=min(dp[i],h+dp[j-1]);
            }
            
        }


        return dp[n];
       
        
    }
};