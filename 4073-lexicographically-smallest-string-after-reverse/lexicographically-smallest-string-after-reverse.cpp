class Solution {
public:
    string fun(int i,string s){
        reverse(s.begin(),s.begin()+i);
        return s;
    }
    string fun2(int i,string s){
        reverse(s.begin()+i,s.end());
        return s;
    }
    
    string lexSmallest(string s) {
        string ans=s;
        for(int i=0;i<s.length();i++){
            ans=min(ans,fun(i,s));   
        }
        for(int i=0;i<s.length();i++){
            ans=min(ans,fun2(i,s));   
        }
        return ans;
        



        
    }
};

