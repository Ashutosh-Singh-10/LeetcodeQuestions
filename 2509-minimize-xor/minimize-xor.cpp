class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int cnt=0;
        int ans=0;
        while(num2) 
        {
            if(num2&1) cnt++;
            num2>>=1;
        }
        for(int i=30;i>=0;i--)
        {
            if(cnt==0)break;
            if(num1 & (1<<i))
            {
                ans=ans ^ (1<<i);
                cnt--;
            }
        }
        for(int i=0;i<=30;i++)
        {
            if(cnt==0) break;
            if( ( ans & (1<<i))==0)
            {
                ans=ans ^ (1<<i);
                cnt--;
            }
        }
        return ans;

        
    }
};