class Solution {
public:
    int countBinarySubstrings(string s) {
        int last=0;
        int cur=-2;
        int cnt=0,ans=0;
        for(auto i:s){
            if(i=='0'){
                if(cur==0){
                    cnt++;
                }
                else {
                    last=cnt;
                    cnt=1;
                    cur=0;
                }
            }
            else {
                if(cur==1){
                    cnt++;
                }
                else {
                    last=cnt;
                    cnt=1;
                    cur=1;
                }
            }
            if(cnt<=last) ans++;
        }
        return ans;
        
    }
};