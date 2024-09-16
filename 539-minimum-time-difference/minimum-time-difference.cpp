class Solution {
public:
    int time(string& a)
    {
        int hr=stoi(a.substr(0,2));
        int min=stoi(a.substr(3,2));
        return hr*60+min;
    }
    // int time_diff(string& a,string& b,int hr_to_add=0)
    // {
        
    //     return time(a,hr_to_add)-time(b,0);
    // }
    int findMinDifference(vector<string>& timepoints) {
        bool *arr=new bool[24*60]();
        int temp;
        for(auto &i:timepoints)
        {
            temp=time(i);
            if(arr[temp]) return 0;
            arr[temp]=1;
        }
        int min=INT_MAX,prev,ans=INT_MAX;
        for(int i=0;i<24*60;i++)
        {
            if(arr[i])
            {
                if(min==INT_MAX)
                {
                    min=i;
                    prev=i;
                }
                else 
                {
                    if(ans>i-prev)
                    {
                        ans=i-prev;
                    }
                    prev=i;
                }

            }

            


        }
        temp=(min+24*60)-prev;
        // cout<<temp;
        if(ans>temp)
        {
            ans=temp;
        }
// ans=min(ans,min+24*60-prev);
        return ans;
        
    }
};