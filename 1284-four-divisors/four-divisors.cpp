class Solution {
public:
    
    int sumFourDivisors(vector<int>& nums) {
        int ans=0;
        for(auto &k:nums){
            int cnt=0;
            int x=0;
            for(int i=2;i*i<=k;i++){

                if(k%i==0) {
                    cnt++;
                    x+=i;
                }
                if(k%i==0 && k/i!=i){
                    cnt++;
                    x+=k/i;
                } 
            }
            if(cnt==2) ans+=x+k+1;
        }
        return ans;
        
    }
};