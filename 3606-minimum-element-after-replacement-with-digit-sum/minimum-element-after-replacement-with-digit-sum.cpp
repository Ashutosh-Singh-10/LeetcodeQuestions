int fun(int num)
{
    int sum=0;
    while(num)
    {
        sum+=num%10;
        num/=10;
    }
    return sum;
}
class Solution {
public:
    int minElement(vector<int>& nums) {
        for(int i=0;i<nums.size();i++) nums[i]=fun(nums[i]);
        return *min_element(nums.begin(),nums.end());

        
    }
};