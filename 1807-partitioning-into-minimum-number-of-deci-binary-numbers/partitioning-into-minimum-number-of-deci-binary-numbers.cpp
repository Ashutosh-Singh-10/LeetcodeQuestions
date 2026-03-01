class Solution {
public:
    int minPartitions(string n) {
        int ans=1;
        for(auto &i:n) ans=max(ans,i-'0');
        return ans;
        
    }
};