class Solution {
public:
    int removeAlmostEqualCharacters(string word) {
        char prev='I';
        int ans=0;
        for(auto &i:word)
        {
            if(abs(prev-i)<=1)
            {
                ans++;
                prev='I';
                
            }
            else prev=i;
            
        }
        return ans;
        
        
        
        
    }
};