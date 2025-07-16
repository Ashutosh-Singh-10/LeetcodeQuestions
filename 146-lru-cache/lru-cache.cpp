class LRUCache {
public:
    unordered_map<int,int> lru,indexing,reverseIndexing;
    // lru - > key value
    // indexing -> index - key
    // reverseIndexing -> key - index;
    int start=0,end=0,capacity;
    LRUCache(int capacity) {
        this->capacity=capacity;
    }
    
    int get(int key) {
        
        if(lru.count(key)==0)
        {
            return -1;
        }
        update(key);
        return lru[key];
        
    }
    void update(int key)
    {
        indexing.erase(reverseIndexing[key]);
        reverseIndexing.erase(key);
        indexing[end]=key;
        reverseIndexing[key]=end;
        end++;

    }
    
    void put(int key, int value) {
        if(lru.count(key)==0)
        {
            if(lru.size()>=capacity)
            {
                while(start<=end)
                {
                    if(indexing.count(start))
                    {
                        reverseIndexing.erase(indexing[start]);
                        lru.erase(indexing[start]);
                        indexing.erase(start);
                        break;

                    }
                    start++;    
                }
                

            }
            lru[key]=value;
            indexing[end]=key;
            reverseIndexing[key]=end;
            end++;
        

        }
        else 
        {
            update(key);
            lru[key]=value;
        }
        
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */