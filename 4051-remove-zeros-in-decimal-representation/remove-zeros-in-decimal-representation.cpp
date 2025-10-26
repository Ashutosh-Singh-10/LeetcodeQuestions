class Solution {
public:
    long long removeZeros(long long n) {
        string s=to_string(n),ans;
        for(auto &i:s) {
            if(i!='0') ans.push_back(i);
        }
        long long ret=0;
        
        for(auto &i:ans) {
            ret*=10ll;
            ret+=i-'0';
        }
        return ret;
        
    }
};