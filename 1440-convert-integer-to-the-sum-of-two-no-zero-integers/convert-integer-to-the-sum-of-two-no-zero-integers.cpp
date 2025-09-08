class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        string a=to_string(n);
        reverse(a.begin(),a.end());
        int carry=0;
        string x,y;
        for(int i=0;i<a.length();i++)
        {
            int val=a[i]-'0';
            if(i==a.length()-1) {
                if(carry) val--;
                if(val==0) break;
                else if(val==1) {
                   x.push_back('1');
                }
                else {
                    x.push_back('0'+(val/2));
                    y.push_back('0'+((val+1)/2));
                }
            }
            else {
                if(val-carry<=1){
                    val+=10;
                    val-=carry;
                    carry=1;
                }
                else {
                    val-=carry;
                    carry=0;
                }
                    x.push_back('0'+(val/2));
                    y.push_back('0'+((val+1)/2));

            }
            
        }
        reverse(x.begin(),x.end());
        reverse(y.begin(),y.end());
        return {stoi(x),stoi(y)};
        
        
    }
};