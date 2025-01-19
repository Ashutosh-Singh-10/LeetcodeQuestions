class Solution {
public:
    int trapRainWater(vector<vector<int>>& hm) {
        int m=hm.size();
        int n=hm[0].size();

        if(m<3 || n<3) return 0 ;
        priority_queue<
        pair<int,pair<int,int>>,
        vector<    pair<int,pair<int,int>>>,
        greater<    pair<int,pair<int,int>>>>pq
    
    ; 
        for(int i=0;i<m;i++)
        {
            
            pq.push({hm[i][n-1],{i,n-1}});
            pq.push({hm[i][0],{i,0}});
            hm[i][n-1]=-1;
            hm[i][0]=-1;

        }
        for(int i=1;i<n-1;i++)
        {
            
            pq.push({hm[m-1][i],{m-1,i}});
            pq.push({hm[0][i],{0,   i}});
            hm[m-1][i]=-1;
            hm[0][i]=-1;
        }
        vector<vector<int>> vec={{-1,0},{0,-1},{0,1},{1,0}};
        int ans=0,val,x,y;
        while(pq.size())
        {
            val=pq.top().first;
            x=pq.top().second.first;
            y=pq.top().second.second;
            pq.pop();
            for(auto &i:vec)
            {
                if(x+i[0]>=0 && y+i[1]>=0 && x+i[0]<m && y+i[1]<n && hm[x+i[0]][y+i[1]] !=-1)
                {
                    if(hm[x+i[0]][y+i[1]]<val)
                    {
                        ans+=val-hm[x+i[0]][y+i[1]];
                    }
                    pq.push({max(hm[x+i[0]][y+i[1]],val),{x+i[0],y+i[1]}});
                    hm[x+i[0]][y+i[1]]=-1;

                }
            }

        }
        return ans;
        
    }
};