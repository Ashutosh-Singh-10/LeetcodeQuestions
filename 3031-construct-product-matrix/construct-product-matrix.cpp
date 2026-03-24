int mod=12345;
class Solution {
public:
    int get(vector<vector<int>> &r,int m,int x){
        return r[x/m][x%m];
    }
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> l(n,vector<int>(m,0));
        vector<vector<int>> r(n,vector<int>(m,0));
        int p=1;
        for(int i=0;i<n*m;i++){

            p=(p*(grid[i/m][i%m]%mod))%mod;
            l[i/m][i%m]=p;
        }
        p=1;
        for(int i=n*m-1;i>=0;i--){
            p=(p*(grid[i/m][i%m]%mod))%mod;
            r[i/m][i%m]=p;
        }
        
        for(int i=0;i<n*m;i++){
            if(i==0){
                grid[i/m][i%m]=get(r,m,i+1);
            }
            else if(i==n*m-1){
                grid[i/m][i%m]=get(l,m,i-1);
            }
            else {
                grid[i/m][i%m]=(get(l,m,i-1)*get(r,m,i+1))%mod;
                
            }
        }
        return grid;
    
        
    }
};