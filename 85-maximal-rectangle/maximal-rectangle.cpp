class Solution {
public:
  
    int maximalRectangle(vector<vector<char>>& mat) {
        int cnt=0;
        int m=mat.size(),n=mat[0].size();
        vector<vector<int>> vec;
        for(int i=0;i<m;i++)
        {
            cnt=0;
            vec.push_back({});
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]=='1') cnt++;
                else cnt=0;
                vec[vec.size()-1].push_back(cnt);

            }

        }
        int ans=0;
        int temp;

        for(int j=0;j<n;j++)
        {
            stack<pair<int,int>> st;
            for(int i=0;i<m;i++)
            {
                    temp=i;
                    while(st.size() && st.top().first>vec[i][j] )
                    {
                        temp=st.top().second;
                        ans=max(ans,st.top().first*(i-temp));
                        st.pop();
                    }
                    st.push({vec[i][j],temp});
                
            }
            while(st.size())
            {
                ans=max(ans,st.top().first*(m-st.top().second));
                st.pop();
            }
            
        }
        return ans;
        
    }
};