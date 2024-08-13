class Solution {
public:
    void algo(vector<vector<int>> & ans ,map<int,int>& mp,vector<int>numbers,int target,int sum,map<int,int>:: iterator it)
    {

        if(sum>target) return ;
        if(it==mp.end()) return;
        int x=it->second;
        int y=it->first;
        it++;
         algo(ans,mp,numbers,target,sum,it);
    
        while(x--)
        {
     
            numbers.push_back(y);
            sum+=y;
            if(target==sum)
            {
                ans.push_back(numbers);
                return ;
            }
            algo(ans,mp,numbers,target,sum,it);

        }
        return ;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> numbers;
        int sum=0;
        map<int,int> mp;
        for(auto &i:candidates)
        {
            if(mp.count(i)) mp[i]++;
            else mp[i]=1;
        }
 
        algo(ans,mp,numbers,target,0,mp.begin());
        return ans;
        
    }
};