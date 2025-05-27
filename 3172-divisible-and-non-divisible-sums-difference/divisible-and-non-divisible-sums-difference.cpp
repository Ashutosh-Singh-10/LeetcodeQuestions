class Solution {
public:
    int differenceOfSums(int n, int m) {
        int tm=n/m;
        return (n*(n+1))/2-(m*2*(tm*(tm+1))/2);
        
    }
};