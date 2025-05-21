class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<bool> row(n,0);
        vector<bool> col(m,0);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                row[i]=matrix[i][j]==0?1:row[i];
                col[j]=matrix[i][j]==0?1:col[j];
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(row[i]==1)
                {
                    matrix[i][j]=0;
                }
                if(col[j]==1)
                {
                    matrix[i][j]=0;
                }
            }
        }
        

        
    }
};