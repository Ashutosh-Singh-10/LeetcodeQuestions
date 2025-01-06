class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n=boxes.size();
        vector<int> vec(n,0);
        int cnt=0,cost=0;
        for(int i=0;i<n;i++)
        {
            cost+=cnt;
            if(boxes[i]=='1') 
            {
                cnt++;
            }
            vec[i]+=cost;
        } 
        cost=0;
        cnt=0;
        for(int i=n-1;i>=0;i--)
        {
            cost+=cnt;
            if(boxes[i]=='1') 
            {
                cnt++;
            }
            vec[i]+=cost;
        } 
        return vec;        
        
    }
};