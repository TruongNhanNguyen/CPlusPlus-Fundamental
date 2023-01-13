# Trie

A trie, also known as a prefix tree, is a tree-based data structure that is commonly used for efficient retrieval of a key in a large dataset of strings. Each node in a trie represents a single character of a word, and each edge represents a transition from one character to the next. The value of the node is stored only at the leaf node, which is the node representing the last character of the word.

A trie is an efficient way of storing large amounts of words because it is able to determine, for any given string, the set of words that begin with that string. This is because, in a trie, each node down a particular branch represents a common prefix shared by all the keys following that branch.

Some common operations that can be performed on a Trie are:

- Insertion of a key: Adding a new key to the trie
- Searching a key: Check if a key is present in the trie or not
- Deletion of a key: Removing a key from the trie
- Count number of keys with a given prefix

## Implementation

### Trie class

Let's implement a basic Trie class in C++ and its basic operations like insertion, searching and deletion of key,

```cpp
class TrieNode
{
public:
    TrieNode *children[26];
    bool endOfWord;
    TrieNode()
    {
        for (int i = 0; i < 26; i++)
        {
            children[i] = nullptr;
        }
        endOfWord = false;
    }
};

class Trie
{
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode();
    }
    void insert(std::string word)
    {
        TrieNode *current = root;
        for (int i = 0; i < word.length(); i++)
        {
            int index = word[i] - 'a';
            if (!current->children[index])
            {
                current->children[index] = new TrieNode();
            }
            current = current->children[index];
        }
        current->endOfWord = true;
    }
    bool search(std::string word)
    {
        TrieNode *current = root;
        for (int i = 0; i < word.length(); i++)
        {
            int index = word[i] - 'a';
            if (!current->children[index])
            {
                return false;
            }
            current = current->children[index];
        }
        return current->endOfWord;
    }
    void deleteWord(std::string word)
    {
        deleteWord(root, word, 0);
    }
    void deleteWord(TrieNode *root, std::string word, int i)
    {
        if (root)
        {
            if (i == word.length())
            {
                root->endOfWord = false;
                return;
            }
            int index = word[i] - 'a';
            deleteWord(root->children[index], word, i + 1);
            if (isFreeNode(root->children[index]))
            {
                free(root->children[index]);
                root->children[index] = nullptr;
            }
        }
    }
    bool isFreeNode(TrieNode *root)
    {
        for (int i = 0; i < 26; i++)
        {
            if (root->children[i])
            {
                return false;
            }
        }
        return true;
    }
};
```

### Test Cases

```cpp
int main() {
    Trie* trie = new Trie();

    trie->insert("hello");
    trie->insert("world");
    trie->insert("hi");

    std::cout << trie->search("hello") << std::endl; // Output: 1
    std::cout << trie->search("hi") << std::endl; // Output: 1
    std::cout << trie->search("worlds") << std::endl; // Output: 0
    trie->deleteWord("hi");
    std::cout << trie->search("hi") << std::endl; // Output: 0
    return 0;
}
```

This will insert the words "hello", "world" and "hi" into the trie, then it will search for the words "hello", "hi" and "worlds" in the trie and it will delete the word "hi" from the trie and again check for the presence of "hi" in trie.

This is just a basic implementation, there are many other variations of trie and more advanced algorithms that can be implemented, like *Ternary Search Trie*, *Suffix Trie*, *Compressed Trie* and many more.