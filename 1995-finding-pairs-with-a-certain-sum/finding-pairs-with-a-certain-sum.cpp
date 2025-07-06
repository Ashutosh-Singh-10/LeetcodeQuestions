class FindSumPairs {
public:
    map<int,int> a,b;
    vector<int> nums1,nums2;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        for(auto &i:nums1)
        {
            a[i]++;
        }
        for(auto &i:nums2)
        {
            b[i]++;
        }
        this->nums1=nums1;
        this->nums2=nums2;
        
    }
    
    void add(int index, int val) {
        b[nums2[index]]--;
        nums2[index]+=val;
        b[nums2[index]]++;
    }
    
    int count(int tot) {
        int ans=0;
        for(auto &[x,y]:a)
        {
            ans+=y*b[tot-x];
        }
        return ans;
        
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */