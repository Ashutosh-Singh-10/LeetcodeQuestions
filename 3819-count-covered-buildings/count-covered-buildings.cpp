class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& vec) {
        map<int,vector<pair<int,int>>> a,b;
        for(int i=0;i<vec.size();i++){
            int x=vec[i][0],y=vec[i][1];
            a[x].push_back({y,i});
            b[y].push_back({x,i});
        }
        vector<int> st(vec.size(),0);
        for(auto &[c,d]:a){
            sort(d.begin(),d.end());
            st[d[0].second]=1;
            st[d.back().second]=1;
        }
        for(auto &[c,d]:b){
            sort(d.begin(),d.end());
            st[d[0].second]=1;
            st[d.back().second]=1;
        }
        int ans=0;
        for(auto &i:st) if(i==0) ans++;
        return ans;
        
    }
};