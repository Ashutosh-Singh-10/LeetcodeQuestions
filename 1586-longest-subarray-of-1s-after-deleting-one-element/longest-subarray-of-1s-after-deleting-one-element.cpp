class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        stack<int> st;
        int count=1;
        
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]==nums[i-1])
            {
                count++;
            }
            else
            {
                st.push(count);
                count=1;
            }
        }
        int prev=0;
        st.push(count);
        if(nums[nums.size()-1]==1)
        {
            prev=st.top();
            st.pop();
        }

        if(st.size()==0) return nums.size()-1;
        int curr=0;
        int ans=prev;
        int zero;
        while(st.size())
        {
            zero=st.top();
            st.pop();
            
            if(st.size())
            {
                curr=st.top();
                if(zero==1)
                {
                    ans=max(prev+curr,ans);
                }
                ans=max(curr,ans);
                prev=curr;
                st.pop();
            }
            

        }
        return ans;

        



        
    }
};