class EventManager {
public:
    map<int,int> mp;
    set<pair<int,int>> st;
    EventManager(vector<vector<int>>& events) {
        for(auto &i:events){
            st.insert({i[1],-i[0]});
            mp[i[0]]=i[1];
        }

    }
    
    void updatePriority(int eventId, int newPriority) {
        st.erase(st.find({mp[eventId],-eventId}));
        st.insert({newPriority,-eventId});
        mp[eventId]=newPriority;
    }
    
    int pollHighest() {
        if(st.size()==0) return -1;
        auto it=st.end();
        it--;
        int ans=it->second;
        st.erase(it);
        ans=-ans;
        mp.erase(ans);
        return ans;
        
    }
};

/**
 * Your EventManager object will be instantiated and called as such:
 * EventManager* obj = new EventManager(events);
 * obj->updatePriority(eventId,newPriority);
 * int param_2 = obj->pollHighest();
 */