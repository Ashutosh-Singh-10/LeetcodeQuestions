int fun(int x,int y)
{
    int i=0;
    while(1)
    {
        if(i%2)
        {
            if(x>i)
            {
                x-=i+1;
            }
            else return i;
        }
        else 
        {
            if(y>i)
            {
                y-=i+1;
            }
            else return i;
        }
        i++;
    }
    return i;

}
class Solution {
public:
    int maxHeightOfTriangle(int red, int blue) {
        return max(fun(red,blue),fun(blue,red));

        
    }
};