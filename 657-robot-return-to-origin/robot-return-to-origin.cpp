class Solution {
public:
    bool judgeCircle(string moves) {
        int a=0,b=0;
        for(auto &i:moves){
            if(i=='L') a--;
            else if(i=='R') a++;
            else if(i=='U') b++;
            else b--;
        }
        return (a==0)&&(b==0)?1:0;
        
    }
};