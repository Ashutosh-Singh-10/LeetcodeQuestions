class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> ans(n,vector<int> (n,0));
        for(auto q:queries){
            int l1=q[0],r1=q[1],l2=q[2],r2=q[3];
            for(int i=l1;i<=l2;i++){
                ans[i][r1]++;
                if(r2!=n-1){
                    ans[i][r2+1]--;
                }
            }
        }
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<n;j++){
                cnt+=ans[i][j];
                ans[i][j]=cnt;
            }
        }
        return ans;
        
    }
};