class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
			int xl=INT_MAX;
			int xs=0;
			int yl=INT_MAX;
			int ys=0;
			int n=grid.size();
            int m=grid[0].size();
			for(int i=0;i<n;i++)
			{
                for(int j=0;j<m;j++)
				{
					if(grid[i][j]==1)
					{
						xl=min(i,xl);
						xs=max(i,xs);
                        
						yl=min(j,yl);
						ys=max(j,ys);
					}
				}
			}

			return (xs-xl+1)*(ys-yl+1);


        
    }
};