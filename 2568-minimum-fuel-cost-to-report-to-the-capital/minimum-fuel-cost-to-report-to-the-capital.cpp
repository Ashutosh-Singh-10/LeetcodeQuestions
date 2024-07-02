long long dfs(vector<vector<int>> & gr,long long & ans,int &seats,int cur,int prev)
{
    long long sum=1;
    for(auto &i:gr[cur])
    {
        if(i!=prev)
        {
            sum+=dfs(gr,ans,seats,i,cur);

        }
        
    }
    if(cur!=0)
    ans+=sum/seats+(sum%seats?1:0);
    return sum;

}
class Solution {
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n=roads.size()+1;
        vector<vector<int>> gr(n);
        for(auto &i:roads) 
        {
            gr[i[0]].push_back(i[1]);
            gr[i[1]].push_back(i[0]);
        }
        long long ans=0;
        dfs(gr,ans,seats,0,-1);
        return ans;


        
    }
};