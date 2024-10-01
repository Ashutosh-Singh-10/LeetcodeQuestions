class Solution {
public:
    bool canArrange(vector<int>& vec, int k) {
        int *arr=new int[k]();
        int temp;
        for(const auto &i:vec)
        {
            temp=i%k;
            if(temp<0)
            {
                arr[k+temp]++;
            }
            else {
                arr[temp]++;
            }
            
        }
        for(int i=1;i<(k+1)/2;i++)
        {
            if(arr[i]!=arr[k-i]) return 0;
        }
        if(k%2==0 && arr[k/2]%2)
        {
            return 0;

        }
        return 1;
        
    }
};