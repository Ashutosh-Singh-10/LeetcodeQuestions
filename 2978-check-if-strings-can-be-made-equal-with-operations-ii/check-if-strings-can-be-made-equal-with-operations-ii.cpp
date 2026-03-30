class Solution {
public:
    void So(string &s){
        sort(s.begin(),s.end());
    }
    bool checkStrings(string s1, string s2) {
        string a,b,c,d;
        for(int i=0;i<s1.length();i++){
            if(i%2) a.push_back(s1[i]);
            else b.push_back(s1[i]);
        }
        for(int i=0;i<s2.length();i++){
            if(i%2) c.push_back(s2[i]);
            else d.push_back(s2[i]);
        }
        So(a);So(b);So(c);So(d);
        return a==c && b==d;
        
    }
};