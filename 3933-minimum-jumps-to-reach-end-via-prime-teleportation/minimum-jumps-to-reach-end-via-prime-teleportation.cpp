int mex=1e6+5;
vector<int> vec(1e6+5,0);
class Solution {
public:
    void calculate(){
        vec[0]=vec[1]=1;
        for(int i=2;i*i<mex;i++)
        {
            if(vec[i]==0)
            {
                for(int j=i+i;j<mex;j+=i)
                {
                    vec[j]=1;

                }
                
            }
        }

    }
    int minJumps(vector<int>& nums) {
        // if(vec[4]==0) 
        calculate();
        int n=nums.size();;
        int mx=0;
        unordered_map<int,vector<int>> data;
        for(int i=0;i<n;i++)
        {
            data[nums[i]].push_back(i);
            mx=max(mx,nums[i]);

        } 
        queue<int> qu;
        vector<int> vis(n,-1);
        vis[0]=0;
        qu.push(0);
        
        int ans=0;
        unordered_set<int> primeVis;
        while(qu.size())
        {
            
            if(qu.front()==n-1) return  vis[n-1];
            int x=qu.front();
            qu.pop();
            
            if(vis[x+1]==-1) 
            {
                qu.push(x+1);
                vis[x+1]=vis[x]+1;
            }
            if(x!=0 && vis[x-1]==-1) 
            {
                qu.push(x-1);
                vis[x-1]=vis[x]+1;
            }
            if(vec[nums[x]]==0 && primeVis.count(nums[x])==0)
            {
                primeVis.insert(nums[x]);
                for(int i=nums[x];i<=mx;i+=nums[x])
                {
                    if(data.count(i)==0) continue;
                    for(auto &j:data[i])
                    {
                        if(vis[j]==-1)
                        {
                            vis[j]=vis[x]+1;
                            qu.push(j);
                        }

                    }
                }
            }
        }
        return 0;



        
    }
};