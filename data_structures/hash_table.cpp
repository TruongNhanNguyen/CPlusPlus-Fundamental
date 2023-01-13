#include <bits/stdc++.h>

template <typename K, typename V>
class HashTable
{
private:
    struct Node
    {
        K key;
        V value;
        Node *next;
    };
    int size;
    Node **table;

    int hashFunction(K key)
    {
        return key % size;
    }

public:
    HashTable(int size) : size(size)
    {
        table = new Node *[size];
        for (int i = 0; i < size; i++)
        {
            table[i] = nullptr;
        }
    }

    ~HashTable()
    {
        for (int i = 0; i < size; i++)
        {
            Node *entry = table[i];
            while (entry != nullptr)
            {
                Node *prev = entry;
                entry = entry->next;
                delete prev;
            }
        }
        delete[] table;
    }

    void put(K key, V value)
    {
        int index = hashFunction(key);
        Node *entry = table[index];
        while (entry != nullptr)
        {
            if (entry->key == key)
            {
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

    V *get(K key)
    {
        int index = hashFunction(key);
        Node *entry = table[index];
        while (entry != nullptr)
        {
            if (entry->key == key)
            {
                return &entry->value;
            }
            entry = entry->next;
        }
        return nullptr;
    }

    void remove(K key)
    {
        int index = hashFunction(key);
        Node *entry = table[index];
        if (entry == nullptr)
        {
            return;
        }
        if (entry->key == key)
        {
            table[index] = entry->next;
            delete entry;
            return;
        }
        Node *prev = entry;
        entry = entry->next;
        while (entry != nullptr)
        {
            if (entry->key == key)
            {
                prev->next = entry->next;
                delete entry;
                return;
            }
            prev = entry;
            entry = entry->next;
        }
    }
};

void test_hashtable()
{
    HashTable<std::string, int> hash_table(10);
    hash_table.put("1", 1);
    hash_table.put("2", 2);
    hash_table.put("3", 3);
    std::cout << "Value of key 1: " << *hash_table.get("1") << std::endl;
    std::cout << "Value of key 2: " << *hash_table.get("2") << std::endl;
    hash_table.remove("2");
    if (hash_table.get("2") == nullptr)
        std::cout << "Key 2 is removed" << std::endl;
}

int main()
{
    test_hashtable();
    return 0;
}
