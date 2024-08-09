class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size(),ans=0;
        for(int i=2;i<n;i++)
        {
            for(int j=2;j<m;j++)
            {
                if(grid[i][j]+grid[i-1][j]+grid[i-2][j]!=15) continue;
                if(grid[i][j-1]+grid[i-1][j-1]+grid[i-2][j-1]!=15) continue;
                if(grid[i][j-2]+grid[i-1][j-2]+grid[i-2][j-2]!=15) continue;

                if(grid[i][j]+grid[i][j-1]+grid[i][j-2]!=15) continue;
                if(grid[i-1][j]+grid[i-1][j-1]+grid[i-1][j-2]!=15) continue;
                if(grid[i-2][j]+grid[i-2][j-1]+grid[i-2][j-2]!=15) continue;

                if(grid[i][j]+grid[i-1][j-1]+grid[i-2][j-2]!=15) continue;
                if(grid[i][j-2]+grid[i-1][j-1]+grid[i-2][j]!=15) continue;
                ans++;
                set<int> st;
                for(int k=i-2;k<=i;k++) 
                {
                    for(int l=j-2;l<=j;l++) 
                    {
                        st.insert(grid[k][l]);
                    }
                }
                if(st.size()!=9 || *st.begin()!=1 || *st.rbegin()!=9) ans--;
                



            }

        }
        return ans;
        
    }
};