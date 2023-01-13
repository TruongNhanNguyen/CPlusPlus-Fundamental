# Binary Tree

## Binary Tree class

Let's implement a basic binary tree class in C++, with basic functions such as adding and deleting nodes, and searching for a node

```cpp
template <typename T>
class BinaryTree {
private:
    struct TreeNode {
        T data;
        TreeNode *left;
        TreeNode *right;
        TreeNode(T data) : data(data), left(nullptr), right(nullptr) {}
    };
    TreeNode *root;

public:
    BinaryTree() : root(nullptr) {}

    void insert(T data) {
        root = insert(root, data);
    }

    TreeNode* insert(TreeNode *node, T data) {
        if (!node) {
            return new TreeNode(data);
        }
        if (data < node->data) {
            node->left = insert(node->left, data);
        } else if (data > node->data) {
            node->right = insert(node->right, data);
        }
        return node;
    }

    void remove(T data) {
        root = remove(root, data);
    }

    TreeNode* remove(TreeNode *node, T data) {
        if (!node) {
            return nullptr;
        }
        if (data < node->data) {
            node->left = remove(node->left, data);
        } else if (data > node->data) {
            node->right = remove(node->right, data);
        } else {
            if (!node->left) {
                return node->right;
            } else if (!node->right) {
                return node->left;
            } else {
                TreeNode *temp = minValueNode(node->right);
                node->data = temp->data;
                node->right = remove(node->right, temp->data);
            }
        }
        return node;
    }

    TreeNode* minValueNode(TreeNode *node) {
        while (node->left) {
            node = node->left;
        }
        return node;
    }

    bool search(T data) {
        return search(root, data);
    }

    bool search(TreeNode *node, T data) {
        if (!node) {
            return false;
        }
        if (data == node->data) {
            return true;
        }
        if (data < node->data) {
            return search(node->left, data);
        }
        return search(node->right, data);
    }
};
```

The `insert` function adds a new node with the given value to the tree. The `remove` function removes a node with the given value from the tree. The `search` function checks whether a node with the given value exists in the tree.

## Test Cases

```cpp
void test_binary_tree() {
    BinaryTree<int> tree;
    tree.insert(5);
    tree.insert(2);
    tree.insert(7);
    tree.insert(4);
    tree.insert(9);

    std::cout << "In-order traversal: ";
    tree.inOrder();
    std::cout << std::endl;

    std::cout << "Search for 4: " << tree.search(4) << std::endl;
    std::cout << "Search for 10: " << tree.search(10) << std::endl;

    std::cout << "Remove node 7: ";
    tree.remove(7);
    tree.inOrder();
    std::cout << std::endl;
}
```

This test case function creates a binary tree, and demonstrates the use of the basic functions provided by the `BinaryTree` class such as `insert`, `remove`, `search`, `inOrder` (for Inorder traversal, that is left-node-right ) which you can add in the class. It inserts nodes with values 5, 2, 7, 4, 9, performs an in-order traversal of the tree, searches for nodes with values 4 and 10, and removes the node with value 7 and again performs an in-order traversal of the tree.

Keep in mind that this is just a basic implementation of a binary tree, and there are many other variations and more advanced algorithms that can be implemented on a tree data structure. Also I have not added the Inorder traversal method you can write it as per your requirement.