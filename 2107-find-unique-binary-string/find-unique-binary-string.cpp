class Solution {
public:
   
    string findDifferentBinaryString(vector<string>& nums) {
        string ans="";
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i][i]=='0')
            {
                ans.push_back('1');
            }
            else
                ans.push_back('0');

        }
        
  return ans;

        
    }
};