class Solution {
public:
    
    string maxSumOfSquares(int num, int sum) {
        int dig=sum/9;
        if(sum%9) dig++;
        if(dig>num) return "";
        string ans;
        while(ans.size()<num){
            if(sum>=9) {
                ans.push_back('9');
                sum-=9;
            }
            else  {
                ans.push_back('0'+sum);
                sum=0;
            }

        }
        return ans;
        
    }
}; 
