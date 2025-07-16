class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int od=0,ev=0,cur=-1;
        int x=0;
        for(auto &i:nums)
        {
            if(i%2) 
            {
                if(cur!=1)
                {
                    x++;
                    cur=1;
                }
                od++;

            }
            else 
            {
                if(cur!=2)
                {
                    x++;
                    cur=2;
                }
                ev++;
            }

        }
        return max(max(od,ev),x);
        
    }
};