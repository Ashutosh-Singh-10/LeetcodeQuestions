class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int a=0,b=0,c=0;
        for(auto &i:nums){
            int d=a+i,e=b+i,f=c+i;
            if(d%3==0) a=max(a,d);
            else if(d%3==1) b=max(b,d);
            else if(d%3==2) c=max(c,d);
            if(e%3==0) a=max(a,e);
            else if(e%3==1) b=max(b,e);
            else if(e%3==2) c=max(c,e);
            if(f%3==0) a=max(a,f);
            else if(f%3==1) b=max(b,f);
            else if(f%3==2) c=max(c,f);
        }
        return a;
        
    }
};