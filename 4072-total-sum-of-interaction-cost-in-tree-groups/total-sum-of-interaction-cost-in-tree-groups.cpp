#define ll long long 



vector<pair<ll,ll>> dfs(vector<vector<ll>> &gr,ll cur,ll prev,vector<int> & group,ll &ans){
    
    vector<pair<ll,ll>> vec(21,{0,0});
    for(auto &i:gr[cur]){
        if(i!=prev){
            auto arr=dfs(gr,i,cur,group,ans);

            for(int j=0;j<21;j++){
                auto [a,b]=vec[j];
                ans+=(b*arr[j].first);
                ans+=(a*arr[j].second);
                vec[j].first+=arr[j].first;
                vec[j].second+=arr[j].second;
            }

        }
    }
    ans+=vec[group[cur]].first;
    vec[group[cur]].second++;
    for(int i=0;i<21;i++){
        vec[i].first+=vec[i].second;
    }
    return vec;
}
class Solution {
public:
    long long interactionCosts(int n, vector<vector<int>>& edges, vector<int>& group) {
        long long ans=0;
        vector<vector<ll>> gr(n);
        for(auto &i:edges) {
            gr[i[0]].push_back(i[1]);
            gr[i[1]].push_back(i[0]);
        }
        dfs(gr,0,-1,group,ans);
        return ans;

        
    }
};