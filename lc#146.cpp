struct node{
    node *prev=nullptr;
    node *next=nullptr;
    int key;
    int value=0;
};
class LRUCache {
private:
    int capacity;
    int size;
    unordered_map<int,node *> hash_m;
    node* head=nullptr;
    node* tail=nullptr;
public:
    LRUCache(int _capacity):capacity(_capacity), size(0) {
        head=new node;
        tail=new node;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (!hash_m.count(key)) return -1;
        else {
            node* temp;
            temp = hash_m[key];
            movetohead(temp);
            return temp->value;
        }
    }
    
    void put(int key, int value) {
        node* temp;
        if(hash_m.count(key)){
            temp=hash_m[key];
            temp->value=value;
            movetohead(temp);
        } else{
            temp = new node;
            temp->value=value;
            temp->key = key;
            add(temp);
            hash_m[key]=temp;
            size++;
            if (size>capacity) {
                temp = tail->prev;
                remove(temp);
                hash_m.erase(temp->key);
                delete temp;
                size--;
            }
        }
    }
    void remove(node* node){
        node->prev->next=node->next;
        node->next->prev=node->prev;
    }
    void add(node* node){
        node->prev=head;
        node->next=head->next;
        head->next->prev=node;
        head->next=node;
    }
    void movetohead(node* node)
    {
        remove(node);
        add(node);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */