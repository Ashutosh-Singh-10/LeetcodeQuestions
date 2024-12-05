class Solution {
public:
    bool canChange(string start, string target) {
        int a=0,b=0;
        for(int i=0;i<start.length();i++)
        {
            if(start[i]=='L') a++;
            if(target[i]=='L') a--;
            if(start[i]=='R') b++;
            if(target[i]=='R') b--;
            if(a>0 || b<0) return 0;
        }
        string s,t;
        for(auto &i:start) if(i!='_') s.push_back(i);
        for(auto &i:target) if(i!='_') t.push_back(i);
        return s==t;



        
    }
};