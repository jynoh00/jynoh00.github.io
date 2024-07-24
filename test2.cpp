#include <iostream>
#include <string>

using namespace std;

class HashNode {
private:
    string key;
    int value;
    HashNode* nextHash;
public:
    HashNode() : nextHash(nullptr) {}
    HashNode(const string& k, int val) : key(k), value(val), nextHash(nullptr) {}

    HashNode* getNext() { return nextHash; }
    void setNext(HashNode* node) { nextHash = node; }
    const string& getKey() { return key; }
    int getValue() { return value; }
};

class HashBucket {
private:
    int size;
    HashNode* head;
public:
    HashBucket() : size(0), head(nullptr) { head = new HashNode; }
    ~HashBucket() {
        HashNode* node = head;
        HashNode* next = nullptr;
        while (node != nullptr) {
            next = node->getNext();
            delete node;
            node = next;
        }
    }

    bool isEmpty() { return size == 0; }
    void push(HashNode* val) {
        HashNode* next = head->getNext();
        head->setNext(val);
        val->setNext(next);
        size++;
    }
    HashNode* findNode(const string& key) {
        HashNode* node = head->getNext();
        while (node != nullptr) {
            if (key == node->getKey()) {
                return node;
            }
            node = node->getNext();
        }
        return nullptr;
    }
    void delNode(const string& key) {
        HashNode* node = head;
        HashNode* prev = nullptr;

        while (node != nullptr) {
            if (node->getKey() == key) {
                if (prev) {
                    prev->setNext(node->getNext());
                } else {
                    head->setNext(node->getNext());
                }
                delete node;
                size--;
                return;
            }
            prev = node;
            node = node->getNext();
        }
    }

    void display() {
        HashNode* node = head->getNext();
        while (node != nullptr) {
            cout << node->getValue() << " ";
            node = node->getNext();
        }
    }
};

class HashTable {
private:
    int bucketSize;
    int size;
    HashBucket* bucket;
    int makeHash(const string& key) {
        int hash = 401; // 소수값

        for (int i = 0; i < key.length(); i++) {
            hash = (hash << 4) + static_cast<int>(key[i]);
        }

        return hash % bucketSize;
    }
public:
    HashTable() : bucketSize(16), size(0) {
        bucket = new HashBucket[bucketSize];
    }
    HashTable(int bSize) : bucketSize(bSize), size(0) {
        bucket = new HashBucket[bSize];
    }
    ~HashTable() { delete[] bucket; }

    void insert(const string& key, int val) {
        int hash = makeHash(key);
        HashNode* overlap = bucket[hash].findNode(key); // 같은 key값 노드가 있는 지 확인

        if (overlap != nullptr) {
            return;
        }
        bucket[hash].push(new HashNode(key, val));
    }
    void del(const string& key) {
        int hash = makeHash(key);
        bucket[hash].delNode(key);
    }
    int find(const string& key) {
        int hash = makeHash(key);
        HashNode* find = bucket[hash].findNode(key);

        if (find == nullptr) return -1;
        return find->getValue();
    }
    int operator[](const string& key) {
        int hash = makeHash(key);
        HashNode* find = bucket[hash].findNode(key);

        if (find == nullptr) {
            return -1;
        }
        return find->getValue();
    }
    void display() {
        for (int i = 0; i < bucketSize; i++) {
            bucket[i].display();
        }
        cout << endl;
    }
};

int main() {
    HashTable ht(10);

    ht.insert("key1", 10);
    ht.insert("key2", 20);
    ht.insert("key3", 30);
    ht.insert("key4", 40);

    cout << "Hash Table: " << endl;
    ht.display();

    cout << "Finding key1: " << ht.find("key1") << endl;
    cout << "Finding key2: " << ht.find("key2") << endl;
    cout << "Finding key3: " << ht.find("key3") << endl;
    cout << "Finding key5: " << ht.find("key5") << endl; // This key does not exist

    ht.del("key2");
    cout << "Hash Table:" << endl;
    ht.display();

    cout << "Finding key2: " << ht.find("key2") << endl; // 값이 없을 때

    cout << ht["key3"] << endl;

    return 0;
}