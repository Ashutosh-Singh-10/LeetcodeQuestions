long long mod=1e9+7;
class Solution {
public:
    void replace(long long &a){
        // if(a==0) return ;
        // int bit=a/abs(a);
        // a=abs(a)%mod;
        // a*=bit;
    }
    int maxProductPath(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<pair<long long,long long>>> vec(n+1,vector<pair<long long,long long>>(m+1,{1,0}));
        int cnt=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                long long el=grid[i-1][j-1];
                if(el==0) cnt++;
                vec[i][j]={0,0};
                if(i==1 && j==1){
                    if(grid[i-1][j-1]<=0){
                        vec[i][j].second=abs(el);
                    }
                    else vec[i][j].first=el;
                    continue; 
                }
                // el=abs(el);
                long long a=(vec[i-1][j].first*el);
                long long b=-(vec[i-1][j].second*el);
                long long c=(vec[i][j-1].first*el);
                long long d=-(vec[i][j-1].second*el);
                if(i==1) {
                    a=0;
                    b=0;
                }
                if(j==1) {
                    c=0;
                    d=0;
                }
                
                // cout<<a<<" "<<b<<" "<<c<<" "<<d<<" | ";
                replace(a);
                replace(b);
                replace(c);
                replace(d);
                long long mn=0,mx=0;
                mn=min({a,b,c,d});
                mx=max({a,b,c,d});
                
                vec[i][j]={mx,-mn};
                // cout<<a<<" "<<b<<" "<<c<<" "<<d<<" | "<<mn<<"  "<<mx<<" ---- ";
                

            }
            // cout<<endl;
        }
        // for(auto &i:vec){
        //     for(auto &j:i){
        //         cout<<"[ "<<j.first<<" "<<j.second<<" ]  ";
        //     }
        //     cout<<endl;
        // }
        if(vec[n][m].first>0) return vec[n][m].first%mod;
        if(cnt>0) return 0;
        return -1;
        
        
    }
};



// [[2,1,3,0,-3,3,-4,4,0,-4],
// [-4,-3,2,2,3,-3,1,-1,1,-2],
// [-2,0,-4,2,4,-3,-4,-1,3,4],
// [-1,0,1,0,-3,3,-2,-3,1,0],
// [0,-1,-2,0,-3,-4,0,3,-2,-2],
// [-4,-2,0,-1,0,-3,0,4,0,-3],
// [-3,-4,2,1,0,-4,2,-4,-1,-3],
// [3,-2,0,-4,1,0,1,-3,-1,-1],
// [3,-4,0,2,0,-2,2,-4,-2,4],
// [0,4,0,-3,-4,3,3,-1,-2,-2]]