class Solution {
public:
    int isSym(int n)
    {
        int x=n;
        int cnt=0;
        while(x)
        {
            cnt++;
            x/=10;
        }
        if(cnt%2==1) return 0;
        int sum=0;
        cnt/=2;
        while(cnt)
        {
            sum+=n%10;
            n/=10;
            cnt--;
            
        }
        while(n)
        {
            sum-=n%10;
            n/=10;
            
        }
        // cout<<sum<<"  ";
        if(sum!=0) return 0;
        return 1;
    }
    int countSymmetricIntegers(int low, int high) {
        int ans=0;
        for(int i=low;i<=high;i++)
        {
            ans+=isSym(i);
        }
        return ans;
        
    }
};