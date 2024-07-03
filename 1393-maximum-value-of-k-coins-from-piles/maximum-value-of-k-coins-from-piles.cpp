class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {

        int n=piles.size();
        vector<vector<int>> vec(n+1,vector<int>(k+1,0));
        for(auto &arr:piles)
        {
            for(int i=1;i<arr.size();i++)
            {
                arr[i]+=arr[i-1];
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {

            for(int j=0;j<piles[i].size();j++)
            {
                
                for(int l=0;l<k;l++)
                {
                    if(j+l<k)
                    {
                        vec[i+1][j+1+l]=max({vec[i+1][j+1+l],vec[i][l]+piles[i][j],vec[i][j+1+l]});
                        ans=max(vec[i+1][j+1+l],ans);
                    }

                }
            }
        }
  
        
        return ans;
        


        
    }
};