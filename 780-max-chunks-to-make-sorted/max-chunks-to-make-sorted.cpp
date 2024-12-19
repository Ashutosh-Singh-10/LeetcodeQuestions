class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n=arr.size();
        vector<int> mn(n+1,INT_MAX);
        for(int i=n-1;i>=0;i--) mn[i]=min(mn[i+1],arr[i]);
        int mx=0,ans=0;
        
        for(int i=0;i<n;i++)
        {
            mx=max(mx,arr[i]);
            if(mx<=mn[i+1]) ans++;
        }
        return ans;

        
    }
};