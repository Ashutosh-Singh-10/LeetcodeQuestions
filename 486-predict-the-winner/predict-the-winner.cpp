class Solution {
public:
    int algo(unordered_map<string,int> &mp,int start,int end,int current,vector<int> & nums)
    {
        if(start==end)
        {
            return nums[start];
        }
        
        int next=0;
        
        if(current==0) next=1;
        int left,right;
        
        
        if(mp.count(to_string(start)+"-"+to_string(end)))
        {
            return mp[to_string(start)+"-"+to_string(end)];
        }
        left=algo(mp,start+1,end,next,nums);
        right=algo(mp,start,end-1,next,nums);
        if(current==1 )
        {

            mp[to_string(start)+"-"+to_string(end)]=max(left+nums[start],right+nums[end]);
            return max(left+nums[start],right+nums[end]);
        }
        else 
        {
            mp[to_string(start)+"-"+to_string(end)]=min(left-nums[start],right-nums[end]);

            return min(left-nums[start],right-nums[end]);

        }


    }
    bool predictTheWinner(vector<int>& nums) {
        if(nums.size()%2==0) return 1;
        unordered_map<string,int> mp;
        
        
        int ans= algo(mp,0,nums.size()-1,1,nums);
        if(ans>=0) return 1;
        return 0;
        
    }
};