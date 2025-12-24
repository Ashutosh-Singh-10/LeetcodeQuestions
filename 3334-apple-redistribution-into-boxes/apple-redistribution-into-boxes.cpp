class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& c) {
        int n=c.size();
        int x=0;
        for(auto &i:apple) x+=i;
        sort(c.begin(),c.end());
        int i=c.size()-1;
        while(i>=0)
        {
            if(x<=c[i])
            {
                return n-i;
            }
            x-=c[i];
            i--;
        }
        return n;
        
    }
};