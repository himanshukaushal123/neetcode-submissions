class LRUCache {
public:
    class Node {
    public:
        int val;
        int k;
        Node* prev;
        Node* next;

        // CHANGED 1: Initialize the actual class members
        Node(int key, int v) {
            val = v;
            k = key;
            prev = NULL;
            next = NULL;
        }
    };

    // CHANGED 2: ump -> mp because you use mp everywhere
    unordered_map<int, Node*> mp;

    int cap;

    // CHANGED 3: head and tail need to be class members
    Node* head;
    Node* tail;

    LRUCache(int capacity) {
        cap = capacity;

        // CHANGED 4: removed "Node*" because head/tail are already members
        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }

    // CHANGED 5: insert an existing node instead of creating a new one
    void insert(Node* temp) {
        temp->next = tail;
        temp->prev = tail->prev;

        tail->prev->next = temp;
        tail->prev = temp;
    }

    void remove(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    int get(int key) {
        // key not present
        if (mp.find(key) == mp.end())
            return -1;

        // key present
        Node* temp = mp[key];

        // remove from current position
        remove(temp);

        // CHANGED 6: insert the SAME node instead of creating a new node
        insert(temp);

        return temp->val;
    }

    void put(int key, int value) {

        // key present
        if (mp.find(key) != mp.end()) {

            Node* node = mp[key];

            // CHANGED 7: value -> val
            node->val = value;

            remove(node);

            // CHANGED 8: insert the same node
            insert(node);

            return;
        }

        // cache full
        // CHANGED 9: siz() -> size()
        if (mp.size() == cap) {

            Node* lru = head->next;

            remove(lru);

            // CHANGED 10: key -> k
            mp.erase(lru->k);

            delete lru;
        }

        // CHANGED 11: create the node properly
        Node* node = new Node(key, value);

        // Add at tail
        insert(node);

        // Add in map
        mp[key] = node;

        // CHANGED 12: removed cap++
        // cap is the maximum capacity and should NOT increase
    }
};
