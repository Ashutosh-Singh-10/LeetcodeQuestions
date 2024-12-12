class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq;
        for(auto &i:gifts) pq.push(i);
        while(k--)
        {
            auto i=pq.top();
            pq.pop();
            pq.push(sqrt(i));
        }
        long long ans=0;
        while(pq.size()) 
        {
            ans+=pq.top();
            pq.pop();
        }
        return ans;
       

        
    }
};