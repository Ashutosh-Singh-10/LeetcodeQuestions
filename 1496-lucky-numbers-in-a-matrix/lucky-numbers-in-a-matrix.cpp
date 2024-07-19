class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> min_in_row;
        vector<int> max_in_column;
        int x;
        int index;
        for(int i=0;i<matrix.size();i++)
        {
            x=matrix[i][0];
            index=0;
            
            for(int j=0;j<matrix[0].size();j++)
            {
                if(matrix[i][j]<x)
                {
                    x=matrix[i][j];
                    index=j;
                }
            }
            min_in_row.push_back(index);
        }

           for(int i=0;i<matrix[0].size();i++)
        {
            x=matrix[0][i];
            index=0;
            
            for(int j=0;j<matrix.size();j++)
            {
                if(matrix[j][i]>x)
                {
                    x=matrix[j][i];
                    index=j;
                }
            }
            max_in_column.push_back(index);
        }
        vector<int> ans;
    
        for(int k=0;k<min_in_row.size();k++)
        {
            for(int i=0;i<max_in_column.size();i++)
            {
                if(max_in_column[i]==k && min_in_row[k]==i)
                {
                    ans.push_back(matrix[max_in_column[i]][min_in_row[k]]);
                    break;
                }
            }
        }
        return ans;
        
    }
};