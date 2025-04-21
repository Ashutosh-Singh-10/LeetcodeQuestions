class Solution {
public:
    int checker(int mid,vector<int> &weights)
    {
        int days=1,current_weight=0;
        for(auto &i:weights)
        {
            if(i>mid) return 1e9;
            if(current_weight+i>mid)
            {
                current_weight=i;
                days++;
            }
            else
            {
                current_weight+=i;
            }
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int high=1e9,low=1,mid,ans=1e9;
        while(high>=low)
        {
            mid=low+(high-low)/2;
            int require_day=checker(mid,weights);
            if(require_day<=days)
            {
                ans=min(mid,ans);  
                high=mid-1;
            }
            else 
            {
                low=mid+1;
            }
        }
        return ans;
    }
};