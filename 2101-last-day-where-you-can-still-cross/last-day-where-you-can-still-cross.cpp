class Solution {
public:
    int n,m;
    int d[5] = {0,1,0,-1,0};
    bool dfs(vector<vector<int>>&vis,vector<vector<int>>&v,int i,int j){
        vis[i][j]=1;
        if(i==n-1)return true;
        bool ans = false;
        for(int k=0;k<4;k++){
            int ni = i + d[k];
            int nj = j + d[k+1];
            if(ni>=0 && nj>=0 && ni<n && nj<m && !vis[ni][nj] && !v[ni][nj]){
                ans |= dfs(vis,v,ni,nj);
            }
        }
        return ans;
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cell) {
        int l=0,r=cell.size()-1;
        n = row;
        m = col;
        int day=0;
        while(l<=r){
            int mid = (l+r)/2;
            vector<vector<int>>v(row,vector<int>(col,0));
            for(int i=0;i<=mid;i++){
                v[cell[i][0]-1][cell[i][1]-1]=1;
            }
           vector<vector<int>>vis(row,vector<int>(col,0));
           bool ans=false;
           for(int i=0;i<col;i++){
               if(vis[0][i]==0 && v[0][i]==0){
                   ans |= dfs(vis,v,0,i);
               }
           }
           if(ans){
               day=mid;
               l=mid+1;
           }
           else{
               r = mid - 1;
           }
        }
        return day+1;
    }
};

// class Solution {
// public:
//     bool available(vector<vector<int>> & grid,int &index,int x,int y,int row,int col)
//     {
//         if(x>=row || x<0 || y<0 || y>=col 
//         || 
//         grid[x][y]==index
//         )
//         {
//             return 0;
//         }
//         return 1;
//     }
//     bool bfs(vector<vector<int>> & grid,vector<vector<int>> & endday,int &index,int day)
//     {
    
//         queue<pair<int,int>> q;
//         vector<vector<int>> vec={{1,0},{-1,0},{0,1},{0,-1}};
//         for(int i=0;i<grid[0].size();i++)
//         {
//             if(endday[0][i]>day)
//             {
//                 q.push({0,i});
//             }
//         }
//         q.push({-1,-1});
//         int x,y;
//         while(q.size()>1)
//         {
//             x=q.front().first;
//             y=q.front().second;
//             q.pop();
//             cout<<x<<"  "<<y<<endl;
//             if(x==-1)
//             {
//                 cout<<"###################"<<endl;
//                 q.push({-1,-1});
//                 day++;
//                 continue;
                
//             }
//             grid[x][y]=index;
//             if(endday[x][y]<=day)
//             {
//                 continue;
//             }
//             if(x==grid.size()-1)
//             {
//                 return 1;
//             }
//             for(auto &i:vec)
//             {

//                 if(available(grid,index,x+i[0],y+i[1],grid.size(),grid[0].size()))
//                 {  
//                     q.push({x+i[0],y+i[1]});
//                 }
//             }
//         }
//         return 0;
        


//     }

//     int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
//         vector<vector<int>> endday(row,vector<int>(col,0));
//         vector<vector<int>> grid(row,vector<int>(col,0));
//         int day=1;
//         for(auto &i:cells)
//         {
//             endday[i[0]-1][i[1]-1]=day;
//             day++;
//         }
//         for(const auto &i:endday) {for(const auto &j:i) cout<<j<<"  ";cout<<endl;}
//         cout<<endl<<endl;
//         int start=0;
//         int end=row*col-1;
//         int index=1,mid;
//         while(start<end)
//         {
//             mid=start+(end-start)/2;
//             if(bfs(grid,endday,index,mid))
//             {
//                 start=mid+1;
//             }
//             else
//             {
//                 end=mid;
//             }
//             index++;
            
//             cout<<"done  "<<mid<<endl;
//         }
//         return (start+end)/2;
//         return mid;
          


        
//     }
// };