class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        set<string> st;
        map<string,string>ma,mb;
        set<char> vowel={'a','i','o','u','e','A','E','I','O','U'};
        for(auto &i:wordlist) {
            st.insert(i);
            string a,b;
            for(auto &j:i){
                if(j<97 ) a.push_back(j+'a'-'A');
                else a.push_back(j);
                if(vowel.count(j)) b.push_back('a');
                else if(j<97) b.push_back(j+'a'-'A');
                else b.push_back(j);

            }
            if(ma.count(a)==0) ma[a]=i;
            if(mb.count(b)==0) mb[b]=i;
        }
        vector<string> ans;
        for(auto &[a,b]:mb) {
        }
        for(auto &i:queries) {
            if(st.count(i)) {
                ans.push_back(i);
                continue;
            }
            string a,b;
            for(auto &j:i){
                if(j<97 ) a.push_back(j+'a'-'A');
                else a.push_back(j);
                if(vowel.count(j)) b.push_back('a');
                else if(j<97) b.push_back(j+'a'-'A');
                else b.push_back(j);

            }
            if(ma.count(a)) ans.push_back(ma[a]);
            else if(mb.count(b)) ans.push_back(mb[b]);
            else ans.push_back("");
        }
        return ans;
        
    }
};