class Solution {
public:
    bool check(vector<long long> &vec){
        long long sum=0;
        for(auto &i:vec) sum+=i;
        long long x=0;
        for(auto &i:vec) {
            sum-=i;
            x+=i;
            if(sum==x) return 1;
        }
        return 0;
    }
    bool canPartitionGrid(vector<vector<int>>& grid) {
        vector<long long> a,b;
        for(auto &i:grid){
            long long x=0;
            for(auto &j:i) x+=j;
            a.push_back(x);
        }
        for(int i=0;i<grid[0].size();i++){
            long long x=0;
            for(int j=0;j<grid.size();j++){
                x+=grid[j][i];
            }
            b.push_back(x);
        }
        return check(a) || check(b);
        
    }
};