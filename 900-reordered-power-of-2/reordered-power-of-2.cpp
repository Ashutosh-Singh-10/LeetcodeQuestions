class Solution {
public:
    int size(int x) 
    {
        int ans=0;
        while(x) {ans++;x/=10;}
        return ans;
    }
    bool equal(int a,int b)
    {
        string x=to_string(a);
        string y=to_string(b);
        sort(x.begin(),x.end());
        sort(y.begin(),y.end());
        return x==y;
    }
    bool reorderedPowerOf2(int n) {
        map<int,vector<int>> mp;
        int x=1;
        while(x<=1e9)
        {
            mp[size(x)].push_back(x);
            x<<=1;
        }
        int sz=size(n);
        for(auto &i:mp[sz]) 
        {
            if(equal(i,n))return true;
        }
        return false;
        
        
    }
};