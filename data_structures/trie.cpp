#include <bits/stdc++.h>

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

void test_Trie()
{
    Trie trie;
    trie.insert("hello");
    trie.insert("world");
    trie.insert("hi");
    assert(trie.search("hello") == true);
    assert(trie.search("world") == true);
    assert(trie.search("hi") == true);
    assert(trie.search("hell") == false);
    trie.deleteWord("hello");
    assert(trie.search("hello") == false);
    assert(trie.search("world") == true);
    assert(trie.search("hi") == true);
}

int main()
{
    test_Trie();
    return 0;
}
