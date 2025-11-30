class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        int n=nums.size();
        int ans=n;
        map<string,int> mp;
        for(int j=0;j<n;j++){
            int i=nums[j];
            string str=to_string(i);
            reverse(str.begin(),str.end());
            if(mp.count(str)){
                ans=min(ans,j-mp[str]);
            } 
            reverse(str.begin(),str.end());
            int flag=0;
            string add;
            while(str.back()=='0') str.pop_back();
            // for(auto &i:str) {
            //     if(flag==1) add.push_back(i);
            //     else if(i!='0'){
            //         flag=1;
            //         add.push_back(i);
            //     }
            // }
            mp[str]=j;
        }
        // for(auto &[a,b]:mp) cout<<a<<"->"<<b<<endl;
        return ans==n?-1:ans;
        
    }
};