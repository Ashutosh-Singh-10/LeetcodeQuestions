#define ll long long
class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        ll a=num1,b=num2;
        for(ll i=1;i<=40;i++)
        {
            
            ll num=a-b*i,cnt=0;
            if(num<i) continue;
            if(num<0) break;
            
            while(num) {

                cnt+=num&1ll;
                num>>=1;
            }
            if(cnt<=i)
            return i;
            
        }
        return -1;
        
        
        
    }
};