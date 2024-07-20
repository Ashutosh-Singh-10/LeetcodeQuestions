class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& a, vector<int>& b) {
        int n=a.size(),m=b.size();
        vector<vector<int>>vec(n,vector<int>(m,0)); 
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int x=min(a[i],b[j]);
                vec[i][j]=x;
                a[i]-=x;
                b[j]-=x;
            }
        }
        return vec;

        
    }
};