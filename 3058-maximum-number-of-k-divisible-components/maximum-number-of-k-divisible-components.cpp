class Solution {
public:
    long long algo(vector<vector<int>> &graph,int curr,int prev,int k,vector<int> &values,int &ans)
    {
        long long sm=values[curr];
        for(auto &i:graph[curr])
        {
            if(i!=prev)
            sm+=algo(graph,i,curr,k,values,ans);
            
        }
        if(sm%k==0)
        {
            // cout<<"THe sm is"<<sm<<"  "<<k<<endl;
            ans++;
            return 0;
        }
            
        return sm;
     

    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<int> ec(n,0);
        vector<vector<int>> graph(n);
        for(auto &i:edges)
        {
            ec[i[0]]++;
            ec[i[1]]++;
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(i[0]);
            
            
        }
        int root=0;
        while(root<n)
        {
            if(ec[root]<2)
            {
                break;
                
            }
            root++;
        }
        // for(auto &i:graph)
        // {
        //     for(auto &j:i) cout<<j<<"  ";
        //     cout<<endl;
        // }
        int ans=0;
        algo(graph,root,-1,k,values,ans);
        // cout<<endl<<"the anss is"<<ans<<"  "<<endl;
        
        return ans;
        
        
    }
};