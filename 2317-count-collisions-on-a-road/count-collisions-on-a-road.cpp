class Solution {
public:
    int countCollisions(string directions) {
        int cnt=0;
        deque<char> dq;
        for(auto &i:directions) dq.push_back(i);
        while(dq.size() && dq.front()=='L') dq.pop_front();
        while(dq.size() && dq.back()=='R') dq.pop_back();
        for(auto &i:dq) if(i=='S') cnt++;
        return dq.size()-cnt;
        
    }
};