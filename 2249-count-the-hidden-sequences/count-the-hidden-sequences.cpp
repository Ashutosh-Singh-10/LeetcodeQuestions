class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long cur=0;
        long long mn=cur,mx=cur;
        for(auto &i:differences)
        {
            cur+=(long long)i;
            mn=min(mn,cur);
            mx=max(cur,mx);
        }
        long long pos_range=mx-mn+1;
        long long range=upper-lower+1;
        if(pos_range>range) return 0;
        return range-pos_range+1;
        
    }
};