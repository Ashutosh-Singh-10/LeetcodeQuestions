class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n=nums.size();
        vector<int> vec(n,0);
        map<int,vector<int>> mp;
        for(int i=0;i<n;i++){
            vec[i]=mp[nums[i]].size();
            mp[nums[i]].push_back(i);
        } 
        vector<int> ans;
        for(auto &i:queries){
            int el=nums[i];
            if(mp[el].size()<2){
                ans.push_back(-1);
                continue;
            }
            ans.push_back(min( 
                {
                abs(mp[el][vec[i]]-mp[el][
                    (vec[i]-1+mp[el].size())%mp[el].size()
                    ]
                ),
                n-abs(mp[el][vec[i]]-mp[el][
                    (vec[i]-1+mp[el].size())%mp[el].size()
                    ]
                ),
                abs(mp[el][vec[i]]-mp[el][
                    (vec[i]+1+mp[el].size())%mp[el].size()
                    ]
                ),
                n-abs(mp[el][vec[i]]-mp[el][
                    (vec[i]+1+mp[el].size())%mp[el].size()
                    ]
                )
                }
            ));
           

        }
        return ans;

        
    }
};