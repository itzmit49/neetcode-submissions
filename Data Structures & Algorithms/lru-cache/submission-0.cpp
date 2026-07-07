class LRUCache {
public:
int limit;
   struct Node{
    int key,value;
    Node * next;
    Node* prev;
    Node(int k,int v){
        key=k;
        value=v;
        prev=next=NULL;
    }
   };
   Node* head=new Node(-1,-1);
   Node* tail=new Node(-1,-1);
   unordered_map<int,Node*>mp;
   void addnode(Node* node){
    Node* temp=head->next;
    head->next=node;
    node->prev=head;
    node->next=temp;
    temp->prev=node;

   }
   void delnode(Node* node){
    Node* prevnode=node->prev;
    Node* nextnode=node->next;
    prevnode->next=nextnode;
    nextnode->prev=prevnode;
   }
    LRUCache(int capacity) {
         limit=capacity;
         head->next=tail;
         tail->prev=head;
        
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end())return -1;
        Node * ansnode=mp[key];
        int ans=ansnode->value;
        delnode(ansnode);
        addnode(ansnode);
        mp[key]=ansnode;
        return ans;
        
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            Node* oldnode=mp[key];
            delnode(oldnode);
            mp.erase(key);
            delete oldnode;
        }
        if(mp.size()==limit){
            Node* lrunode=tail->prev;
            delnode(lrunode);
            mp.erase(lrunode->key);
            delete lrunode;
        }
        Node* newnode= new Node(key,value);
        addnode(newnode);
        mp[key]=newnode;



        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */