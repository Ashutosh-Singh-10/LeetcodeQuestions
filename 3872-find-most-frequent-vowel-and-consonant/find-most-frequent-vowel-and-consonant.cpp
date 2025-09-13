class Solution {
public:
    int maxFreqSum(string s) {
        map<int,int> a,b;
        set<int> st={'a','e','i','o','u'};
        for(auto &i:s) {
            if(st.count(i)) a[i]++;
            else b[i]++;
        }
        int x=0,y=0;
        for(auto &[c,d]:a) {
            x=max(x,d);
        }
        for(auto &[c,d]:b) {
            y=max(y,d);
        }

        return x+y;
        
    }
};