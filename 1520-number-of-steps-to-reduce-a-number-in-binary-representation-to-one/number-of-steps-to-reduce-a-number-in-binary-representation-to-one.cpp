class Solution {
public:
    int numSteps(string s) {
        int ans=0;
        while(s.size()>1){
            ans++;
            if(s.back()=='0') {
                s.pop_back();
            }
            else {
                while(s.size() && s.back()=='1'){
                    s.pop_back();
                    ans++;
                }
                if(s.size()) s.pop_back();
                s.push_back('1');
                
            }
            //  cout<<s<<" "<<endl;
        }
        return ans;

        
    }
};