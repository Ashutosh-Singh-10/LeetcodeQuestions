class Solution {
public:
    string stri(int i){
        string ans;
        while(i){
            ans.push_back((i&1)+'0');
            i>>=1;
        }
        // reverse(ans.begin(),ans.end());
        return ans;
    }
    int concatenatedBinary(int n) {
        int mod=1e9+7;
        int ans=0;
        for(int i=1;i<=n;i++){
            string s=stri(i);
            while(s.size()){
                ans<<=1;
                if(s.back()=='1') ans+=1;
                ans%=mod;
                s.pop_back();
            }

        }
        return ans;
        
    }
};