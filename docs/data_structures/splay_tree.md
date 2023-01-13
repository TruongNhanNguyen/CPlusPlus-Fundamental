# Splay Tree

A Splay tree is a self-adjusting binary search tree. It is a data structure that allows for fast access, insertion and deletion operations. Like other binary search trees, it organizes data in a way that allows for efficient searching, by keeping elements less than a given key on the left side of the tree and elements greater than a given key on the right side of the tree.

Splay trees are different from other binary search trees in how they adjust themselves after a search, insertion or deletion operation. After one of these operations, the accessed node (i.e., the node that was found during a search, or the node that was inserted or deleted) is moved to the root of the tree. This is known as splaying the accessed node.

The main advantage of Splay tree is that the most frequently accessed elements are moved closer to the root and therefore to the top of the tree. Therefore, the time complexity of operations like search, insertion and deletion is $O(\log{n})$ amortized complexity.

## Implementation

### Splay Tree class

```cpp
template <typename T>
class SplayTree {
    struct Node {
        T key;
        Node* left;
        Node* right;
        Node(T key) : key(key), left(nullptr), right(nullptr) {}
    };
    Node* root;

    Node* leftRotate(Node* x) {
        Node* y = x->right;
        x->right = y->left;
        y->left = x;
        return y;
    }

    Node* rightRotate(Node* x) {
        Node* y = x->left;
        x->left = y->right;
        y->right = x;
        return y;
    }

    Node* splay(Node* root, T key) {
        if (!root || root->key == key)
            return root;
        if (root->key > key) {
            if (!root->left)
                return root;
            if (root->left->key > key) {
                root->left->left = splay(root->left->left, key);
                root = rightRotate(root);
            }
            else if (root->left->key < key) {
                root->left->right = splay(root->left->right, key);
                if (root->left->right)
                    root->left = leftRotate(root->left);
            }
            return (root->left == nullptr) ? root : rightRotate(root);
        }
        else {
            if (!root->right)
                return root;
            if (root->right->key > key) {
                root->right->left = splay(root->right->left, key);
                if (root->right->left)
                    root->right = rightRotate(root->right);
            }
            else if (root->right->key < key) {
                root->right->right = splay(root->right->right, key);
                root = leftRotate(root);
            }
            return (root->right == nullptr) ? root : leftRotate(root);
        }
    }

public:
    SplayTree() : root(nullptr) {}

    void insert(T key) {
        if (!root) {
            root = new Node(key);
            return;
        }
        root = splay(root, key);
        if (key < root->key) {
            Node* newNode = new Node(key);
            newNode->right = root;
            newNode->left = root->left;
            root->left = nullptr;
            root = newNode;
        }
        else if (key > root->key) {
            Node* newNode = new Node(key);
            newNode->left = root;
            newNode->right = root->right;
            root->right = nullptr;
            root = newNode;
        }
    }

    void remove(T key) {
        root = splay(root, key);
        if (root->key != key)
            return;
        Node* leftTree = root->left;
        Node* rightTree = root->right;
        delete root;
        if (!rightTree) {
            root = leftTree;
        }
        else {
            root = splay(rightTree, key);
            root->left = leftTree;
        }
    }

    bool search(T key) {
        root = splay(root, key);
        return root->key == key;
    }
    T findMinimum() {
        Node* current = root;
        while (current->left)
            current = current->left;
        return current->key;
    }

    T findMaximum() {
        Node* current = root;
        while (current->right)
            current = current->right;
        return current->key;
    }

    void inorderTraversal() {
        inorderTraversal(root);
    }

    void inorderTraversal(Node* node) {
        if (!node)
            return;
        inorderTraversal(node->left);
        std::cout << node->key << " ";
        inorderTraversal(node->right);
    }
};
```

This is a basic implementation of a Splay Tree that demonstrates the core functionality of `insert`, `remove`, `search`, `findMinimum`, `findMaximum`, and `inorderTraversal`. You can expand on this implementation by adding other functionality as needed, such as an in-order traversal or a function to return the maximum or minimum element in the tree. Additionally, it is good to write test cases to test each function.

### Test Cases

```cpp
void test_splay_tree() {
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
    std::cout<<"Inorder traversal: ";
    st.inorderTraversal();
    std::cout<<"\nMinimum element: "<<st.findMinimum()<<std::endl;
    std::cout<<"Maximum element: "<<st.findMaximum()<<std::endl;
    return 0;
}
```