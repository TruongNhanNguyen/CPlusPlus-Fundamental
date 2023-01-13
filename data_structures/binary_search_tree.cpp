#include <bits/stdc++.h>

template <typename T>
class BinarySearchTree
{
private:
    struct Node
    {
        T data;
        Node *left;
        Node *right;
        Node(T data) : data(data), left(nullptr), right(nullptr) {}
    };
    Node *root;

public:
    BinarySearchTree() : root(nullptr) {}

    void insert(T data)
    {
        root = insert(root, data);
    }

    Node *insert(Node *node, T data)
    {
        if (!node)
        {
            return new Node(data);
        }
        if (data < node->data)
        {
            node->left = insert(node->left, data);
        }
        else
        {
            node->right = insert(node->right, data);
        }
        return node;
    }

    void remove(T data)
    {
        root = remove(root, data);
    }
    Node *remove(Node *node, T data)
    {
        if (!node)
        {
            return nullptr;
        }
        if (data < node->data)
        {
            node->left = remove(node->left, data);
        }
        else if (data > node->data)
        {
            node->right = remove(node->right, data);
        }
        else
        {
            if (!node->left)
            {
                Node *temp = node->right;
                delete node;
                return temp;
            }
            else if (!node->right)
            {
                Node *temp = node->left;
                delete node;
                return temp;
            }
            else
            {
                Node *successor = findMin(node->right);
                node->data = successor->data;
                node->right = remove(node->right, successor->data);
            }
        }
        return node;
    }
    // Helper function that finds the minimum value in a subtree
    Node *findMin(Node *node)
    {
        while (node->left)
        {
            node = node->left;
        }
        return node;
    }
    bool search(T data)
    {
        return search(root, data);
    }

    bool search(Node *node, T data)
    {
        if (!node)
        {
            return false;
        }
        if (data == node->data)
        {
            return true;
        }
        else if (data < node->data)
        {
            return search(node->left, data);
        }
        else
        {
            return search(node->right, data);
        }
    }

    bool contain(T data)
    {
        return search(data);
    }
    void print()
    {
        print(root);
    }

    void print(Node *node)
    {
        if (node)
        {
            print(node->left);
            std::cout << node->data << " ";
            print(node->right);
        }
    }
};

void test_bst()
{
    BinarySearchTree<int> bst;

    bst.insert(50);
    bst.insert(30);
    bst.insert(20);
    bst.insert(40);
    bst.insert(70);
    bst.insert(60);
    bst.insert(80);

    std::cout << "In-order traversal: ";
    bst.print();
    std::cout << std::endl;

    std::cout << "Search for 20: " << bst.search(20) << std::endl;
    std::cout << "Search for 100: " << bst.search(100) << std::endl;

    std::cout << "Removing 20: " << std::endl;
    bst.remove(20);
    bst.print();
    std::cout << std::endl;

    std::cout << "Removing 30: " << std::endl;
    bst.remove(30);
    bst.print();
    std::cout << std::endl;

    std::cout << "Removing 50: " << std::endl;
    bst.remove(50);
    bst.print();
    std::cout << std::endl;
}

int main()
{
    test_bst();
    return 0;
}