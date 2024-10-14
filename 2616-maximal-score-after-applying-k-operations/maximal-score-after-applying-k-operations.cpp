class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<long long> pq;
        for(auto &i:nums) pq.push(i);
        long long ans=0;
        while(k--)
        {
            ans+=pq.top();
            pq.push(ceil((double)pq.top()/(double)3));
            pq.pop();
        }
        return ans;
        
    }
};