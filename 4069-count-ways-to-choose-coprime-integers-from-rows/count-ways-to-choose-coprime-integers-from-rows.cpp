class Solution {
public:
    int countCoprime(vector<vector<int>>& mat) {
        unordered_map<long long,long long> mp,tp;
        long long mod=1e9+7;
        for(auto &i:mat[0]) mp[i]++;
        int n=mat.size();
        for(int i=1;i<n;i++){
            for(auto &el:mat[i]){
                for(auto &[a,b]:mp){
                    int x=__gcd((int)a,el);
                    tp[x]=(tp[x]+b)%mod;
                    
                    
                }
            }
            mp=tp;
            tp.clear();

        }
        return mp[1];
        
    }
};