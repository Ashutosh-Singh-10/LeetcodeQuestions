class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double wt=0;
        int cur=0;
        for(auto &i:customers)
        {
            auto a=i[0];
            auto b=i[1];
            if(cur>=a)
            {
                wt+=cur-a;
            }
            wt+=b;
            cur=max(cur,a)+b;
        }
        return wt/(double)customers.size();
        
    }
};