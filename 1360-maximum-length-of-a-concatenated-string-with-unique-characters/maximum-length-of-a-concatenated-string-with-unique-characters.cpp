class Solution {
public:
    int maxLength(vector<string>& arr) {
        vector<int> vec;
        for(auto &i:arr){
            int x=0;
            for(auto &j:i){
                x=(x|(1<<(j-'a')));
            }
            if((int)__builtin_popcount(x)==(int)i.size())
            vec.push_back(x);
            
        }
        int n=vec.size(),ans=0;
        for(int b=0;b<(1<<n);b++){
            int ro=0,cnt=0;
            for(int i=0;i<n;i++)
            {
                if(b&(1<<i)) {
                    ro|=vec[i];
                    cnt+=__builtin_popcount(vec[i]);
                }
            }
            if(cnt==(int)__builtin_popcount(ro)){
                ans=max(ans,cnt);
                
            }
        }
        return ans;
        
    }
};