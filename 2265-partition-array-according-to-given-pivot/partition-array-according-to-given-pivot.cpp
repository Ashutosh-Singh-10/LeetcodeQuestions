class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n=nums.size(),x=0;
        vector<int> ans(n);
        for(int i=0;i<n;i++) if(nums[i]<pivot) {
            ans[x]=nums[i];x++;
        }
        for(int i=0;i<n;i++) if(nums[i]==pivot) {
            ans[x]=nums[i];x++;
        }
        for(int i=0;i<n;i++) if(nums[i]>pivot) {
            ans[x]=nums[i];x++;
        }
        return ans;
        
    }
};