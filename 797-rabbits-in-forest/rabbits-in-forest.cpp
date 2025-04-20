class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int> rabbits;
        int a,b,ans=0;
        for(const auto &i:answers)
        {
            if(i==0) ans++;
            else if(rabbits.count(i))
            {
                rabbits[i]++;
            }
            else rabbits[i]=1;
        }
        for(const auto &i:rabbits)
        {
            a=i.first+1;
            b=i.second;
            
            ans+=a*(b/a + (b%a>0));
        }
        return ans;
    
        
    }
};