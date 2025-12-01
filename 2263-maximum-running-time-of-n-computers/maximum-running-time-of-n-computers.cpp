class Solution {
public:
    int check(vector<int> &vec,long long mid,long long n){
        long long cnt=0,rem=0;
       for(auto &i:vec){
            if(i>=mid){
                cnt++;
                rem=0;
                continue;
            }
            if(rem+i>=mid){
                cnt++;
                rem=rem+i-mid;
            }
            else rem+=i;

       } 
       return cnt>=n;
    }
    long long maxRunTime(int n, vector<int>& vec) {
        long long high=1e18,low=0,ans=0;
        sort(vec.begin(),vec.end(),greater<int>());
        while(low<=high){
            long long mid=low+(high-low)/2;
            if(check(vec,mid,n)){
                ans=max(ans,mid);
                low=mid+1;
            }
            else high=mid-1;
        }
        return ans;
        
        
    }
};