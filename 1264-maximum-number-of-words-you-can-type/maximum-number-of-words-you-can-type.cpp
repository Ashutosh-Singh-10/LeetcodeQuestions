class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        set<int> st;
        for(auto &i:brokenLetters) st.insert(i);
        text.push_back(' ');
        int ans=0,cnt=0;
        for(auto &i:text) {
            if(i==' ') {
                if(cnt==0) {
                    ans++;
                }
                cnt=0;
            }
            else if(st.count(i)) cnt++;
        }
        return ans;
        
    }
};