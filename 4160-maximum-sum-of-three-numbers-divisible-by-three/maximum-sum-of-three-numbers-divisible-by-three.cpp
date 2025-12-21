class Solution {
public:
    int maximumSum(vector<int>& nums) {
        multiset<int> a,b,c;
        for(auto &i:nums){
            if(i%3==0) a.insert(i);
            else if(i%3==1) b.insert(i);
            else c.insert(i);
            if(a.size()>3) a.erase(a.begin());
            if(b.size()>3) b.erase(b.begin());
            if(c.size()>3) c.erase(c.begin());
        }
        vector<int> vec;
        int ans=0;
        for(auto &i:a) vec.push_back(i);
        for(auto &i:b) vec.push_back(i);
        for(auto &i:c) vec.push_back(i);
        int n=vec.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    if((vec[i]+vec[j]+vec[k])%3==0) 
                    ans=max(ans,vec[i]+vec[j]+vec[k]);
                }
            }
        }
        return ans;
        
    }
};