class Solution {
public:
    
    int stoneGameVII(vector<int>& piles) {
        int n=piles.size();
        vector<int> pre={0};
        vector<vector<int>> dp(n,vector<int> (n,0));
        for(auto &i:piles) pre.push_back(pre.back()+i);
     
        for(int i=n-2;i>=0;i--)
        {
            for(int j=0;j<=i;j++)
            {
                dp[i][j]=max(
                    pre[n-i-1+j] 
                -pre[j]   
                -dp[i+1][j]
                ,
                            pre[n-i+j] 
                            -pre[j+1]  
                             -dp[i+1][j+1] 
                            );
                


            }

        }
        // for(auto &i:dp)
        // {
        //     for(auto &j:i) cout<<j<< " ";cout<<endl;

        // }
        return dp[0][0];
        

         
    }
};