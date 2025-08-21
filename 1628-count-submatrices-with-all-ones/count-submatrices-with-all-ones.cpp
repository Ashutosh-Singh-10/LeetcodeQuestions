class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        vector<vector<int>> vec(n,vector<int>(m,0));
        for(int i=0;i<n;i++) 
        {
            int cnt=0;
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==1) cnt++;
                else cnt=0;
                vec[i][j]=cnt;
            }

        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int tot=1000;
                for(int k=i;k>=0;k--)
                {
                    tot=min(tot,vec[k][j]);
                    ans+=tot;
                
                }
                
            }
            cout<<endl;
        }
        return ans;
        
    }
};