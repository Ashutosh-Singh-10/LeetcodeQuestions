class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        unordered_map<int,int> mp;
        for(int i=0;i<arr.size();i++)
        {
            mp[arr[i]]=i;
        }
        int allMx=INT_MAX,mx=0;
        for(int i=0;i<mat.size();i++)
        {
            mx=-1;
            for(const auto &j:mat[i])
            {
                mx=max(mx,mp[j]);
            }
                if(mx<allMx)
                {
                    allMx=mx;
                }

        }
        for(int i=0;i<mat[0].size();i++)
        {
            mx=-1;
            for(int j=0;j<mat.size();j++)
            {
                mx=max(mx,mp[mat[j][i]]);
            }


             if(mx<allMx)
                {
                    allMx=mx;
                }



        }
        return allMx;
        
    }
};