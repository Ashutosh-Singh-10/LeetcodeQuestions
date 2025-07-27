class Solution {
public:
    long long fun(string s)
    {
        long long l=0,c=0,ans=0;
        for(auto &i:s)
        {
            if(i=='L') l++;
            else if(i=='C') c+=l;
            else if(i=='T') ans+=c;
        }
        return ans;
    }
    long long numOfSubsequences(string s) {
        long long ans=max(fun("L"+s),fun(s+"T"));
        long long tmp=fun(s);
        long long t=0,l=0;
        for(auto &i:s) if(i=='T') t++;
        for(auto &i:s) 
        {
            if(i=='L') l++;
            else if(i=='T') t--;
            ans=max(ans,tmp+l*t);
        }
        return ans;
    }
};