class Solution {
public:
    int algo2(vector<int> &vec, int sq,int index,int num,int sum)
    {
        if(index==vec.size())
        {
       
                if(sq==sum+num)
                {
                    return 1;
                }
            return 0;
                
                
            
           
        }
        return algo2(vec,sq,index+1,vec[index],sum+num) || algo2(vec,sq,index+1,num*10+vec[index],sum);
  
        
    }
    
    int algo(int num)
    {
        vector<int> vec;
        int sq=num*num;
        int temp=sq;
        while(sq)
        {
            vec.push_back(sq%10);
            sq/=10;
        }
        reverse(vec.begin(),vec.end());
  
        
        if(algo2(vec,num,0,0,0)) return temp;
        return 0;
        
    }
    int punishmentNumber(int n) {
        int ans=0;
        // algo(36);
        for(int i=1;i<=n;i++)
        {
            ans+=algo(i);
            // cout<<algo(i)<<endl;
    
        }
        return ans;
        
    }
};