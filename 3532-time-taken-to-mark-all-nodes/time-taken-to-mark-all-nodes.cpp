class Solution {
public:
    void dfs(vector<vector<int>> &gr,int cur,int prev,int cost,int &next,vector<int> &vec,int &mxcost)
    {
        
        vec[cur]=max(vec[cur],cost);
         if(cur%2) cost++;
        else cost+=2;
        if(mxcost<cost) 
        {
            mxcost=cost;
            next=cur;
        }
        for(auto &i:gr[cur])
        {
            if(i!=prev) 
            {
                // if(i%2==0)  
                // dfs(gr,i,cur,cost+2,next,vec,mxcost);
                // else
                // dfs(gr,i,cur,cost+1,next,vec,mxcost);
                dfs(gr,i,cur,cost,next,vec,mxcost);
            }
        }

    }
    vector<int> timeTaken(vector<vector<int>>& edges) {
        int n=edges.size()+1;
        vector<vector<int>> gr(n);
        vector<int> vec(n,0);
        for(auto &i:edges) 
        {
            gr[i[0]].push_back(i[1]);
            gr[i[1]].push_back(i[0]);
        }
        int mxcost=0;
        int next=0;
        dfs(gr,0,-1,0,next,vec,mxcost);
        mxcost=0;
        dfs(gr,next,-1,0,next,vec,mxcost);
        mxcost=0;
        dfs(gr,next,-1,0,next,vec,mxcost);
        mxcost=0;
        dfs(gr,next,-1,0,next,vec,mxcost);
        mxcost=0;
        dfs(gr,next,-1,0,next,vec,mxcost);
        return vec;
        
    }
};