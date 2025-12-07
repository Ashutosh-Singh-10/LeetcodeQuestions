class Solution {
public:
    int countOdds(int low, int high) {
        int ans=(high-low+1)/2;
        if((high-low)%2==0 && high%2==1)
        return ans+1;
        return ans;
        
    }
};