# Hash Table

A hash table (or hash map) is a data structure that stores a collection of key-value pairs, where each key is unique. The keys are used to index into an array, called the *bucket array*, which contains the values.

Hash tables are used for a variety of tasks, such as:

- Fast lookups of values based on their keys.
- Fast implementation of other data structures such as sets or maps.

A key point in the implementation of a hash table is the *hash function*, which is used to map each key to an index in the bucket array. The hash function takes a key as input and returns an index in the array.
The process of converting a key to an index is called *hashing*.

Once the index is obtained, the value is stored or retrieved from the corresponding bucket in the array. The index can be calculated by taking the remainder of the key divided by the size of the array (also called *modulo operation*).

The time complexity of lookups, insertions and deletions in a hash table is typically constant, $O(1)$, on average, assuming a good hash function and a properly-sized table. But in worst case, if all the keys are hashed to the same index and we have a collision, it can degrade to $O(n)$ in worst case.

## Implementation

### Hash Table class

```cpp
template <typename K, typename V>
class HashTable {
  private:
    struct Node {
        K key;
        V value;
        Node* next;
    };
    int size;
    Node** table;

    int hashFunction(K key) {
        return key % size;
    }

  public:
    HashTable(int size) : size(size) {
        table = new Node*[size];
        for (int i = 0; i < size; i++) {
            table[i] = nullptr;
        }
    }

    ~HashTable() {
        for (int i = 0; i < size; i++) {
            Node* entry = table[i];
            while (entry != nullptr) {
                Node* prev = entry;
                entry = entry->next;
                delete prev;
            }
        }
        delete[] table;
    }

    void put(K key, V value) {
        int index = hashFunction(key);
        Node* entry = table[index];
        while (entry != nullptr) {
            if (entry->key == key) {
                entry->value = value;
                return;
            }
            entry = entry->next;
        }
        entry = new Node();
        entry->key = key;
        entry->value = value;
        entry->next = table[index];
        table[index] = entry;
    }

    V* get(K key) {
        int index = hashFunction(key);
        Node* entry = table[index];
        while (entry != nullptr) {
            if (entry->key == key) {
                return &entry->value;
            }
            entry = entry->next;
        }
        return nullptr;
    }

    void remove(K key) {
        int index = hashFunction(key);
        Node* entry = table[index];
                if (entry == nullptr) {
            return;
        }
        if (entry->key == key) {
            table[index] = entry->next;
            delete entry;
            return;
        }
        Node* prev = entry;
        entry = entry->next;
        while (entry != nullptr) {
            if (entry->key == key) {
                prev->next = entry->next;
                delete entry;
                return;
            }
            prev = entry;
            entry = entry->next;
        }
    }
};
```

This class is a basic implementation of a hash table, which uses an array to store a linked list at each index ( bucket) and uses a basic hash function which is the modulus of the key divided by the size of the array as the index.

It uses template types for key and value which allows for flexibility and ease of use.
It has a constructor to create the hash table and initialize the array with nullptrs and a destructor that frees up the memory of the hashtable after use. You can also add other functions such as `put`, `get`, `remove` to this class, to put values in the hash table, get values and remove values based on the keys.


### Test cases

```cpp
void test_hashtable() {
    HashTable<string,int> hash_table(10);
    hash_table.put("1",1);
    hash_table.put("2",2);
    hash_table.put("3",3);
    std::cout << "Value of key 1: " << *hash_table.get("1") << std::endl;
    std::cout << "Value of key 2: " << *hash_table.get("2") << std::endl;
    hash_table.remove("2");
    if(hash_table.get("2") == nullptr)
        std::cout << "Key 2 is removed" << std::endl;
}
```

This test case function will add values to the hash table, retrieve the value of keys and remove one key. It checks if the key is present in the table by calling get method, if it returns a nullptr, it means the key is removed or not present in the table.