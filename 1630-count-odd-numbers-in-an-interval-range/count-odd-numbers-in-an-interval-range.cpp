class Solution {
public:
    int countOdds(int low, int high) {
        return ((high-low)%2==0 && high%2==1)?(high-low+1)/2+1:(high-low+1)/2;
        int ans=(high-low+1)/2;
        if((high-low)%2==0 && high%2==1)
        return ans+1;
        return ans;
        
    }
};