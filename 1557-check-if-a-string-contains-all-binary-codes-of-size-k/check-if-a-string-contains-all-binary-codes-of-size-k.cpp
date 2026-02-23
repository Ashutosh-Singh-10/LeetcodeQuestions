class Solution {
public:
    bool hasAllCodes(string s, int k) {
        set<string> st;
        for(int i=0;i<=(int)(s.length())-k;i++){
            string str=s.substr(i,k);
            st.insert(str);

        }
        
        
        return st.size()==(1<<(k));
        
    }
};