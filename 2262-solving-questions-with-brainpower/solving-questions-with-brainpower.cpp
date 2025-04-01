class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long> vec (questions.size(),0);
        long long mxx=0,mx=0;

        for(int i=0;i<questions.size();i++)
        {
            
            mxx=max(mxx,vec[i]);
            vec[i]=max(mxx,vec[i])+questions[i][0];
            
            if(questions[i][1]+i+1<questions.size())
            {
                vec[i+1+questions[i][1]]=max(vec[i+1+questions[i][1]],vec[i]);
            }   
            mx=max(mx,vec[i]);

            
        }
        return mx;
        


    }
};