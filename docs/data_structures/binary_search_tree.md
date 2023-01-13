# Binary Search Tree - BST

A binary search tree (BST) is a binary tree where the value of each node is greater than or equal to the values of its left children, and less than or equal to the values of its right children. This property of BST allows for efficient searching, insertion, and deletion of elements. The basic operations that can be performed on a BST are:

- **Insertion**: Adding a new node to the tree
- **Deletion**: Removing a node from the tree
- **Searching**: Finding a specific node in the tree
- **Traversal**: Visiting all the nodes in the tree in a specific order

## Implementation

### Binary Search Tree class

```cpp
template <typename T>
class BinarySearchTree {
private:
    struct Node {
        T data;
        Node *left;
        Node *right;
        Node(T data) : data(data), left(nullptr), right(nullptr) {}
    };
    Node *root;

public:
    BinarySearchTree() : root(nullptr) {}

    void insert(T data) {
        root = insert(root, data);
    }

    Node* insert(Node *node, T data) {
        if (!node) {
            return new Node(data);
        }
        if (data < node->data) {
            node->left = insert(node->left, data);
        } else {
            node->right = insert(node->right, data);
        }
        return node;
    }

    void remove(T data) {
        root = remove(root, data);
    }
    bool search(T data) {
        return search(root, data);
    }

    bool search(Node *node, T data) {
        if (!node) {
            return false;
        }
        if (data == node->data) {
            return true;
        } else if (data < node->data) {
            return search(node->left, data);
        } else {
            return search(node->right, data);
        }
    }
    bool contain(T data){
        return search(data);
    }
    void print() {
        print(root);
    }

    void print(Node *node) {
        if (node) {
            print(node->left);
            std::cout << node->data << " ";
            print(node->right);
        }
    }
};

```

As you can see, the `BinarySearchTree` class stores a tree of `Nodes` where each node contains a value and pointers to its left and right children. The `insert` function is recursive and starts at the root node, comparing the given value to the value of the current node. If the value is less than the current node, it moves to the left child, otherwise it moves to the right child. When it reaches a null child, it creates a new node with the given value.

The `remove` function is also recursive and starts at the root node. It traverses the tree by comparing the value of the node to be removed to the current node and then it will move to the left or right child depending on whether the value to remove is less or greater than the current node. It will then remove the node and replaces it with the appropriate child or subtree, in order to maintain the BST property.

The `search` function takes a value as input and returns whether that value is present in the BST or not. It starts at the root node and recursively compares the value to the current node's value. If the value is less than the current node's value, it moves to the left child, otherwise it moves to the right child. It continues this process until it either finds the value or reaches a null node, indicating that the value is not in the tree.

The `contain` method is an alias of `search` method.

The `print` method is a wrapper function for an in-order traversal of the tree, which visits the left child, the current node, and then the right child of each node in the tree. This prints out the nodes in the tree in ascending order. You can change the method to get the output in other order if required, like preorder and postorder.

> **Notes:** Keep in mind that this is just a basic implementation and there are many other variations and more advanced algorithms that can be implemented on a Binary Search Tree. Let me know if you have any other question or want further elaboration on anything.

### Test Cases

```cpp
void test_bst() {
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
```

This test case function creates a binary search tree, inserts nodes with values 50, 30, 20, 40, 70, 60, 80, performs an in-order traversal of the tree, searches for nodes with values 20 and 100, and removes nodes with values 20, 30, 50 and again performs an in-order traversal of the tree after each removal. You can also test the contain method using this test cases function.

This test case function is for an illustration purpose, you can write more test cases to cover various scenarios and test the functionality of the class throughly.