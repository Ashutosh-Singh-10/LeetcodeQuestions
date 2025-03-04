#define ll long long 
class Solution {
public:
    bool checkPowersOfThree(int n) {
        ll x=3;
        set<ll> st;
        while(n>=3)
        {
            if(x*3ll>n) 
            {
                if(st.count(x)) return 0;
                st.insert(x);
                n-=x;
                x=3;


            }
            else x*=3ll;

        }
        return n<=1?1:0;
        
        
    }
};