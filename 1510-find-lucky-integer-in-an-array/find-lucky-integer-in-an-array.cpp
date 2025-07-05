class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int> u_map;
        for(int i=0;i<arr.size();i++)
        {
            if(u_map.count(arr[i])) u_map[arr[i]]++;
            else u_map[arr[i]]=1;
        }
        int max=-1;
        for(auto &i:u_map)
        {
            if(i.first==i.second && i.first>max)
            {
                max=i.first;
            }
        }
        return max;
        
    }
};