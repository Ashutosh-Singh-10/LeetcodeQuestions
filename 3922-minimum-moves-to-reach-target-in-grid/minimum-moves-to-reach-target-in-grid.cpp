class Solution {
public:
    int minMoves(int sx, int sy, int tx, int ty) {
        int ans=0;
        while(tx>=sx && ty>=sy)
        {
            if(tx==sx && ty==sy) return ans;
            ans++;
            
            if(ty==tx)
            {
                int tmp=max(minMoves(sx,sy,tx,0) , minMoves(sx,sy,0,ty));
                if(tmp==-1) return -1;

                return ans+tmp;
            }
            if(ty>=tx)
            {
                if(ty>=tx*2)
                {
                    if(ty%2) return -1;
                    ty/=2;

                }
                else ty-=tx;

            }
            else 
            {
                
                if(tx>=ty*2)
                {
                    if(tx%2) return -1;
                    tx/=2;
                }
                else tx-=ty;

            }
            cout<<tx<<" "<<ty<<endl;
        }
        return -1;
        
    }
};