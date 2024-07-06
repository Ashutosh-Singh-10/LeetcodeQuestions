class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& vec, int k) {
        
        int n=vec.size();
        for(int i=0;i<k-1;i++)
        {
            vec.push_back(vec[i]);
        }
        int ans=0;
        int idx=0;
        for(int i=0;i<vec.size()-1;i++)
        {
            int a=1,b=1;
            if(i && vec[i-1]==vec[i]) a=0;
            if(i<vec.size()-1 && vec[i+1]==vec[i]) b=0;
            if(b==0 || a==0)
            {
                idx=i;
                if(i>=n) return ans;
            }
            else if(i-idx+2>=k) ans++;

        }
        return ans;
        
    }
};