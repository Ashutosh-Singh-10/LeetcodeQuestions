class Solution {
public:
    int countSeniors(vector<string>& details) {
            string str="";
        int num;
        int ans=0;
            for(const auto &i:details)
            {
                str=i.substr(11,2);
                num=stoi(str);
                // cout<<num<<"  ";
                if(num>60)
                {
                    
                    ans++;
                }
            }
        return ans;
    }
};