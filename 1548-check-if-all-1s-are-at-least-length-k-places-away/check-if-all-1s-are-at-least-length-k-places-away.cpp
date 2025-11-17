class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int l=k+1;
        for(auto &i:nums){
            if(i==0) l++;
            else if(l<k) return 0;
            else l=0;
        }
        return 1;
        
    }
};