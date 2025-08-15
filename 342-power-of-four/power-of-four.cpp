class Solution {
public:
    bool isPowerOfFour(int n) {
        if( (n!=1 && (n&1)) || n<=0) return false;
        while(n)
        {
            if(n==1) return true;
            if(n&1) return false;
            n>>=1;
            if(n&1) return false;
            n>>=1;

        }
        
        return false ;        
    }
};