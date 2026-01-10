class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int m=s1.length(),n=s2.length();
        vector<vector<int>> vec(m+1,vector<int>(n+1,0));
        for(int i=0;i<=m;i++)
        {
            for(int j=0;j<=n;j++)
            {
                if(i==0 || j==0)
                {
                    vec[i][j]=0;
                }
                else if(s1[i-1]==s2[j-1])
                {
                    vec[i][j]=vec[i-1][j-1]+s1[i-1];
                    
                }
                else
                {
                    vec[i][j]=max(vec[i-1][j],vec[i][j-1]);
                }
            }
        }
        int tot=0;
        for(auto &i:s1) tot+=i;
        for(auto &i:s2) tot+=i;
        return tot-2*vec[m][n];
        
    }
};