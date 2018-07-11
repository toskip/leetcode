class LRUCache {
public:
    int capacity;
    int size;
    queue<int> q;
    map<int,int> count;
    map<int,int> kv;
    LRUCache(int capacity) {
        this->capacity = capacity;
        size = 0;
    }
    
    int get(int key) {
        if(count[key])
        {
            q.push(key);
            count[key]++;
            return kv[key];
        }
        else return -1;
    }
    
    void put(int key, int value) {
        if(count[key])
        {
            count[key]++;
            kv[key] = value;
            q.push(key);
            return;
        }
        if(size==capacity)
        {
            while(count[q.front()]>1)
            {
                count[q.front()]--;
                q.pop();
            }
            count[q.front()]--;
            q.pop();
            size--;
        }
        q.push(key);
        count[key]++;
        kv[key] = value;
        size++;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
