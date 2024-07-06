class Solution {
public:
    int passThePillow(int n, int time) {
        int x=time/(n-1);
        int ex=time%(n-1);
        if(x%2==0) return ex+1;
        else return n-ex;
        
       
    }
};