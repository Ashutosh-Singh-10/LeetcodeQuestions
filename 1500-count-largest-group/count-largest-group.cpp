class Solution {
public:
    int sum_of_digit(int n)
    {
        int ans=0;
        while(n)
        {
            ans+=n%10;
            n/=10;
        }
        
        return ans;
    }
    int countLargestGroup(int n) {
        unordered_map <int,int> u_set;
        int temp;
        for(int i=1;i<=n;i++)
        {
            temp=sum_of_digit(i);
            if(u_set.count(temp))
            {
                u_set[temp]++;
            }
            else u_set[temp]=1;

        }
        int count=0,maximum=0;
  
      for(auto &i:u_set)
      {
          if(maximum<i.second)
          {
              maximum=i.second;
              count=1;
          }
          else if(i.second==maximum)
          {
              count++;
          }
      }
      return count;
        
    }
};