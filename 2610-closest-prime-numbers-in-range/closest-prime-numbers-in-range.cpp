class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<int> prime(right+5,0);
        prime[1]=1;
        prime[0]=1;
        for(int i=2;i<right+5;i++)
        {
            if(prime[i]==1) continue;
            for(int j=i+i;j<=right;j+=i)
            {
                prime[j]=1;
            }
        }
        int prev=-1,first=-1,second=-1;
        for(int i=left;i<=right;i++)
        {
            if(prime[i]==1) continue;
            if(prev==-1) 
            {
                prev=i;
                continue;
            }
            if(first==-1 || i-prev<second-first)
            {
                first=prev;
                second=i;
            }
            if(second-first==2) break;
            prev=i;
        }
        return {first,second};
        
    }
};