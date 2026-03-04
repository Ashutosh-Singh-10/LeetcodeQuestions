class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        vector<int> row,col;
        int n=mat.size(),m=mat[0].size();
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<m;j++){
                cnt+=mat[i][j];
            }
            row.push_back(cnt);
        }
        for(int j=0;j<m;j++){
            int cnt=0;
            for(int i=0;i<n;i++){
                cnt+=mat[i][j];
            }
            col.push_back(cnt);
        }
        int ans=0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++){
                if(row[i]==1 && col[j]==1 && mat[i][j]==1) ans++;
            }
        }
        return ans;
        
    }
};