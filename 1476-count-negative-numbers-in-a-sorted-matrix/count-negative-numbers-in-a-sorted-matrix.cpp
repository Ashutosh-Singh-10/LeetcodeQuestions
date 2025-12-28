class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int x=grid[0].size()-1;
        int ans=0;
        for(int i=0;i<grid.size();i++)
        {
            while(x>=0 && grid[i][x]<0)
            {
                x--;
            }
            
            ans+=grid[0].size()-x-1;

        }
        return ans;
        
    }
};