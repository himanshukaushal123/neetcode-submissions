class LRUCache {
public:

    class Node {
    public:
        int key;
        int value;
        Node *prev;
        Node *next;

        Node(int k, int v) {
            key = k;
            value = v;
            prev = nullptr;
            next = nullptr;
        }
    };

    unordered_map<int, Node*> mp;
    int cap;

    Node *head;
    Node *tail;

    LRUCache(int capacity) {

        cap = capacity;

        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }

    // Remove a node from the DLL
    void remove(Node *node) {

        Node *prevNode = node->prev;
        Node *nextNode = node->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    // Insert right after head (Most Recently Used)
    void insert(Node *node) {

        node->next = head->next;
        node->prev = head;

        head->next->prev = node;
        head->next = node;
    }

    int get(int key) {

        if (mp.find(key) == mp.end())
            return -1;

        Node *node = mp[key];

        remove(node);
        insert(node);

        return node->value;
    }

    void put(int key, int value) {

        // Key already exists
        if (mp.find(key) != mp.end()) {

            Node *node = mp[key];

            node->value = value;

            remove(node);
            insert(node);

            return;
        }

        // Cache full
        if (mp.size() == cap) {

            Node *lru = tail->prev;

            remove(lru);
            mp.erase(lru->key);

            delete lru;
        }

        Node *node = new Node(key, value);

        insert(node);

        mp[key] = node;
    }
};