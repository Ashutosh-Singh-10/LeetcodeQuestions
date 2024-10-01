class Solution {
public:

    // int longestArithSeqLength(vector<int>& nums){
    // int n=nums.size();
    // int ans=0,diff;
    // vector<vector<int>> vec(n+1,vector<int>(1004,0));
    // for(int i=0;i<n;i++)
    // {
    //     for(int j=i+1;j<n;j++)
    //     {
    //         diff=nums[i]-nums[j];
    //         vec[j][501+diff]=max(vec[i][501+diff]+1,2);
    //         if(vec[j][501+diff]>ans)
    //         {
    //             ans=vec[j][501+diff];
    //         }
    //     }
    // }
    // return ans;



    // }


    int longestArithSeqLength(vector<int>& nums) {

        vector<unordered_map<int,int>> vecmap;
        int ans=0,diff,val;
        for(int i=0;i<nums.size();i++)
        {
            vecmap.push_back({});

        }
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                diff=nums[j]-nums[i];
                if(vecmap[i].count(diff))
                {
                    val=vecmap[i][diff]+1;

                }
                else val=2;
                if(vecmap[j].count(diff))
                {
                    val=max(val,vecmap[j][diff]);


                }
                vecmap[j][diff]=val;
                if(val>ans)
                {
                    ans=val;
                }


            }
        }
        return ans;

   

        
    }
};