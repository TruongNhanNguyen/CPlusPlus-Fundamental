#include <bits/stdc++.h>

template <typename T>
class SplayTree
{
    struct Node
    {
        T key;
        Node *left;
        Node *right;
        Node(T key) : key(key), left(nullptr), right(nullptr) {}
    };
    Node *root;

    Node *leftRotate(Node *x)
    {
        Node *y = x->right;
        x->right = y->left;
        y->left = x;
        return y;
    }

    Node *rightRotate(Node *x)
    {
        Node *y = x->left;
        x->left = y->right;
        y->right = x;
        return y;
    }

    Node *splay(Node *root, T key)
    {
        if (!root || root->key == key)
            return root;
        if (root->key > key)
        {
            if (!root->left)
                return root;
            if (root->left->key > key)
            {
                root->left->left = splay(root->left->left, key);
                root = rightRotate(root);
            }
            else if (root->left->key < key)
            {
                root->left->right = splay(root->left->right, key);
                if (root->left->right)
                    root->left = leftRotate(root->left);
            }
            return (root->left == nullptr) ? root : rightRotate(root);
        }
        else
        {
            if (!root->right)
                return root;
            if (root->right->key > key)
            {
                root->right->left = splay(root->right->left, key);
                if (root->right->left)
                    root->right = rightRotate(root->right);
            }
            else if (root->right->key < key)
            {
                root->right->right = splay(root->right->right, key);
                root = leftRotate(root);
            }
            return (root->right == nullptr) ? root : leftRotate(root);
        }
    }

public:
    SplayTree() : root(nullptr) {}

    void insert(T key)
    {
        if (!root)
        {
            root = new Node(key);
            return;
        }
        root = splay(root, key);
        if (key < root->key)
        {
            Node *newNode = new Node(key);
            newNode->right = root;
            newNode->left = root->left;
            root->left = nullptr;
            root = newNode;
        }
        else if (key > root->key)
        {
            Node *newNode = new Node(key);
            newNode->left = root;
            newNode->right = root->right;
            root->right = nullptr;
            root = newNode;
        }
    }
    void remove(T key)
    {
        root = splay(root, key);
        if (root->key != key)
            return;
        Node *leftTree = root->left;
        Node *rightTree = root->right;
        delete root;
        if (!rightTree)
        {
            root = leftTree;
        }
        else
        {
            root = splay(rightTree, key);
            root->left = leftTree;
        }
    }

    bool search(T key)
    {
        root = splay(root, key);
        return root->key == key;
    }

    T findMinimum()
    {
        Node *current = root;
        while (current->left)
            current = current->left;
        return current->key;
    }

    T findMaximum()
    {
        Node *current = root;
        while (current->right)
            current = current->right;
        return current->key;
    }

    void inorderTraversal()
    {
        inorderTraversal(root);
    }

    void inorderTraversal(Node *node)
    {
        if (!node)
            return;
        inorderTraversal(node->left);
        std::cout << node->key << " ";
        inorderTraversal(node->right);
    }
};

void test_splay_tree()
{
    SplayTree<int> st;
    st.insert(100);
    st.insert(50);
    st.insert(150);
    st.insert(40);
    st.insert(60);
    st.insert(110);
    st.insert(160);
    st.remove(40);
    st.remove(160);
    std::cout << "Inorder traversal: ";
    st.inorderTraversal();
    std::cout << "\nMinimum element: " << st.findMinimum() << std::endl;
    std::cout << "Maximum element: " << st.findMaximum() << std::endl;
}

int main()
{
    test_splay_tree();
    return 0;
}