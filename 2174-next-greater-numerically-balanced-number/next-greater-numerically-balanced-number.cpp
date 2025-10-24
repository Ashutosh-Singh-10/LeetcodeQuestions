class Solution {
public:
    int verify(int x){
        map<int,int> mp;
        while(x){
            mp[x%10]++;
            x/=10;
        }
        for(auto &[a,b]:mp){
            if(a!=b) return 0;
        }
        return 1;
    }
    int nextBeautifulNumber(int n) {
        int i=n;
        while(n==n){
            i++;
            if(verify(i)) return i;
        }
        return 0;

        
    }
};