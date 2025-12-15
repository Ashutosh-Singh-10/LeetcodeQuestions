class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long ans=0;
        long long prev=1e9,cnt=0;
        for(auto &i:prices){
            if(i==prev-1) cnt++;
            else cnt=1;
            ans+=cnt;
            prev=i;
        }
        return ans;

        
    }
};