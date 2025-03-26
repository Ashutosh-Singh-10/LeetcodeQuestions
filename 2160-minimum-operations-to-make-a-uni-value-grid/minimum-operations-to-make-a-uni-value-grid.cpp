class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        
        vector<int> vec;
        int cnt=1;
        for(auto &i:grid) 
        {
            for(auto &j:i) 
            {
                vec.push_back(j);
            }
        }
        if(vec.size()==1) return 0;
        int a=vec[1]-vec[0];
        sort(vec.begin(),vec.end());
        for(int i=1;i<vec.size();i++)
        {
            a=__gcd(vec[i]-vec[i-1],a);
            if(vec[i]==vec[0]) cnt++;

        }
        if(cnt==vec.size()) return 0;
        
        if(a%x) return -1;
        
        int vl=vec[vec.size()/2];
        int ans=0;
        for(auto &i:vec) ans+=abs(i-vl);
        return ans/x;
        
    }
};