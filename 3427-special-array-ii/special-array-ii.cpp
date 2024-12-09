class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {

        int n=nums.size();
        vector<int> vec(n,0);
        for(int i=1;i<n;i++)
        {
            vec[i]=vec[i-1];
            if((nums[i]%2)==(nums[i-1]%2))
            {
                vec[i]=vec[i-1]+1;
            }
        }
        vector<bool> ans;
        
        for(auto &i:queries)
        {
            if(i[0]==i[1])
            {
                ans.push_back(1);
            }
            else if(vec[i[1]]-vec[i[0]]==0) 
            {
                ans.push_back(1);
            }
            else ans.push_back(0);
        }
        return ans;
        
    }
};