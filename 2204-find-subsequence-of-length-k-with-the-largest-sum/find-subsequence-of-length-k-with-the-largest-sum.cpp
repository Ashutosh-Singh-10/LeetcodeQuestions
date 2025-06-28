class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> vec(n,0),ans;
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<n;i++) 
        {
            pq.push({nums[i],i});
        }
        while(k>0) 
        {
            k--;
            auto [a,b]=pq.top();
            pq.pop();
            vec[b]=1;
        }
        for(int i=0;i<n;i++) if(vec[i]==1) ans.push_back(nums[i]);
        return ans;
        
    }
};