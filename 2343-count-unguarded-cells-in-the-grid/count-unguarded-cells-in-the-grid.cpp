class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> vis(m,vector<int>(n,0));
        for(auto &i:guards)
        {
            vis[i[0]][i[1]]=1;
        }
        for(auto &i:walls)
        {
            vis[i[0]][i[1]]=2;
        }
        int ans=0;
        vector<vector<int>> dir={{0,1},{-1,0},{1,0},{0,-1}};
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(vis[i][j]!=1) continue;
                for(auto &d:dir)
                {
                    int x=i,y=j;
                    while(1)
                    {
                        x+=d[0];
                        y+=d[1];
                        if(x<0 || x>=m || y<0 || y>=n) break;
                        if(vis[x][y]==0)
                        {
                            ans++;
                            vis[x][y]=3;
                        }
                        else if(vis[x][y]!=3) break;

                    }
                    
                }
            }
        }
 
        return n*m-ans-walls.size()-guards.size();
    }
};