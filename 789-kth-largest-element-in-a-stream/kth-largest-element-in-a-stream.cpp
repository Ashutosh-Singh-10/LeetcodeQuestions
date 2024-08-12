class KthLargest {
public:
    priority_queue<int,vector<int> ,greater<int> > pq;
    int kth;
    KthLargest(int k, vector<int>& nums) {
        for(const auto &i:nums)
        {
            pq.push(i);
        }
       
        for(int i=0;i<int(nums.size())-k;i++)
        {
            pq.pop();
        }
        kth=k;
        
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>kth)
        pq.pop();
        return pq.top();
     return 0;   
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */