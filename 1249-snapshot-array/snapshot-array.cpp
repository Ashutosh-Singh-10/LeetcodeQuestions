class SnapshotArray {
public:
    set<int> st;
    vector<map<int,int>> vec;
    int sid=0;
    SnapshotArray(int length) {
        vec.resize(length);
    }
    
    void set(int index, int val) {
        vec[index][sid]=val;
        
    }
    
    int snap() {
        sid++;
        return sid-1;
    }
    
    int get(int index, int snap_id) {
        if(vec[index].size()==0) return 0;
        auto it=vec[index].upper_bound(snap_id);
        if(it==vec[index].begin()) return 0;
        it--;
        return it->second;
        
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */