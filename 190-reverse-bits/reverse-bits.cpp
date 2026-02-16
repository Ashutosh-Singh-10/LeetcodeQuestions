class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        
        uint32_t ans=0;
        int count=0;
        int bit=0;
        while(n)
        {
            bit=n&1;
            count++;
            ans<<=1;
            ans+=bit;
            n>>=1;

        }
        while(count<32)
        {
            ans<<=1;
            count++;
        }

      
        return ans;
    }
};