#include <bits/stdc++.h>

class Node
{
public:
    int key;
    int height;
    Node *left;
    Node *right;

    Node(int key)
    {
        this->key = key;
        this->height = 1;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class AVLTree
{
    Node *root;
    int height(Node *node)
    {
        if (!node)
        {
            return 0;
        }
        return node->height;
    }
    Node *rightRotate(Node *node)
    {
        Node *leftChild = node->left;
        Node *leftRightChild = leftChild->right;

        leftChild->right = node;
        node->left = leftRightChild;

        node->height = std::max(height(node->left), height(node->right)) + 1;
        leftChild->height = std::max(height(leftChild->left), height(leftChild->right)) + 1;

        return leftChild;
    }
    Node *leftRotate(Node *node)
    {
        Node *rightChild = node->right;
        Node *rightLeftChild = rightChild->left;

        rightChild->left = node;
        node->right = rightLeftChild;

        node->height = std::max(height(node->left), height(node->right)) + 1;
        rightChild->height = std::max(height(rightChild->left), height(rightChild->right)) + 1;

        return rightChild;
    }
    int balanceFactor(Node *node)
    {
        if (!node)
        {
            return 0;
        }
        return height(node->left) - height(node->right);
    }
    Node *insert(Node *node, int key)
    {
        if (!node)
        {
            return new Node(key);
        }
        if (key < node->key)
        {
            node->left = insert(node->left, key);
        }
        else if (key > node->key)
        {
            node->right = insert(node->right, key);
        }
        else
        {
            return node;
        }
        node->height = 1 + std::max(height(node->left), height(node->right));
        int balance = balanceFactor(node);
        if (balance > 1 && key < node->left->key)
        {
            return rightRotate(node);
        }
        if (balance < -1 && key > node->right->key)
        {
            return leftRotate(node);
        }
        if (balance > 1 && key > node->left->key)
        {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        if (balance < -1 && key < node->right->key)
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
        return node;
    }
    Node *remove(Node *root, int key)
    {
        if (!root)
        {
            return root;
        }
        if (key < root->key)
        {
            root->left = remove(root->left, key);
        }
        else if (key > root->key)
        {
            root->right = remove(root->right, key);
        }
        else
        {
            if (!root->left || !root->right)
            {
                Node *temp = root->left ? root->left : root->right;
                if (!temp)
                {
                    temp = root;
                    root = nullptr;
                }
                else
                {
                    *root = *temp;
                }
                delete temp;
            }
            else
            {
                Node *temp = root->right;
                while (temp->left)
                {
                    temp = temp->left;
                }
                root->key = temp->key;
                root->right = remove(root->right, temp->key);
            }
        }
        if (!root)
        {
            return root;
        }
        root->height = 1 + std::max(height(root->left), height(root->right));
        int balance = balanceFactor(root);
        if (balance > 1 && balanceFactor(root->left) >= 0)
        {
            return rightRotate(root);
        }
        if (balance > 1 && balanceFactor(root->left) < 0)
        {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
        if (balance < -1 && balanceFactor(root->right) <= 0)
        {
            return leftRotate(root);
        }
        if (balance < -1 && balanceFactor(root->right) > 0)
        {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
        return root;
    }
    Node *search(Node *root, int key)
    {
        if (!root)
        {
            return nullptr;
        }
        if (root->key == key)
        {
            return root;
        }
        if (root->key < key)
        {
            return search(root->right, key);
        }
        return search(root->left, key);
    }

public:
    AVLTree()
    {
        this->root = nullptr;
    }
    void insert(int key)
    {
        root = insert(root, key);
    }
    void remove(int key)
    {
        root = remove(root, key);
    }
    bool search(int key)
    {
        return search(root, key) != nullptr;
    }
};

void test_AVL_Tree()
{
    AVLTree tree;

    tree.insert(9);
    tree.insert(5);
    tree.insert(10);
    tree.insert(0);
    tree.insert(6);
    tree.insert(11);
    tree.insert(-1);
    tree.insert(1);
    tree.insert(2);

    std::cout << "Search for 10: " << tree.search(10) << std::endl;
    std::cout << "Search for 15: " << tree.search(15) << std::endl;

    tree.remove(10);

    std::cout << "Search for 10: " << tree.search(10) << std::endl;
}

int main()
{
    test_AVL_Tree();
    return 0;
}