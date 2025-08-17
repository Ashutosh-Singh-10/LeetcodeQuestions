class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if(k==0) return 1;
        deque<double> dq;
        dq.push_back(1);
        double sum=1,ans=0;
        
        for(int i=1;i<=n;i++)
        {
            if(dq.size()>maxPts) 
            {
                sum-=dq.front();
                dq.pop_front();
            }
            
            double cur=sum/maxPts;
            if(i>=k)
            {
                ans+=cur;
                dq.push_back(0);
            }
            else{
                sum+=cur;
                dq.push_back(cur); 
            } 
            
        }
        return ans;
       
    }
};