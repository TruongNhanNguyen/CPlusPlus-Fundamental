#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

struct Node
{
    char data;
    int freq;
    Node *left;
    Node *right;

    Node(char data, int freq) : data(data), freq(freq), left(nullptr), right(nullptr) {}

    bool operator>(const Node &other) const
    {
        return freq > other.freq;
    }
};

void assignCodes(Node *root, unordered_map<char, string> &codes, string code)
{
    if (!root)
        return;
    if (root->data != '\0')
    {
        codes[root->data] = code;
    }
    assignCodes(root->left, codes, code + "0");
    assignCodes(root->right, codes, code + "1");
}

unordered_map<char, string> buildHuffmanTree(unordered_map<char, int> &freq_table)
{
    priority_queue<Node, vector<Node>, greater<Node>> pq;

    for (auto &entry : freq_table)
    {
        pq.push(Node(entry.first, entry.second));
    }

    while (pq.size() > 1)
    {
        Node *left = new Node(pq.top().data, pq.top().freq);
        pq.pop();
        Node *right = new Node(pq.top().data, pq.top().freq);
        pq.pop();

        Node *parent = new Node('\0', left->freq + right->freq);
        parent->left = left;
        parent->right = right;

        pq.push(*parent);
    }
    Node *root = new Node(pq.top().data, pq.top().freq);
    pq.pop();
    unordered_map<char, string> codes;
    assignCodes(root, codes, "");
    return codes;
}

void test_huffman_coding()
{
    unordered_map<char, int> freq_table = {{'a', 45}, {'b', 13}, {'c', 12}, {'d', 16}, {'e', 9}, {'f', 5}};
    auto codes = buildHuffmanTree(freq_table);
    for (auto &entry : codes)
    {
        cout << entry.first << ": " << entry.second << endl;
    }
}

int main()
{
    test_huffman_coding();
    return 0;
}