class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        for(int i=0;i<bits.size();i++)
        {
            if(i==bits.size()-2)
            {
                if(bits[i]==1) return 0;
                return 1;
            }
            if(bits[i]==1) 
            {
                i++;
            }

        }
        return 1;
        
    }
};