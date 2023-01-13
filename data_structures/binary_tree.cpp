#include <bits/stdc++.h>

template <typename T>
class BinaryTree
{
private:
    struct TreeNode
    {
        T data;
        TreeNode *left;
        TreeNode *right;
        TreeNode(T data) : data(data), left(nullptr), right(nullptr) {}
    };
    TreeNode *root;

public:
    BinaryTree() : root(nullptr) {}

    void insert(T data)
    {
        root = insert(root, data);
    }

    TreeNode *insert(TreeNode *node, T data)
    {
        if (!node)
        {
            return new TreeNode(data);
        }
        if (data < node->data)
        {
            node->left = insert(node->left, data);
        }
        else if (data > node->data)
        {
            node->right = insert(node->right, data);
        }
        return node;
    }

    void remove(T data)
    {
        root = remove(root, data);
    }

    TreeNode *remove(TreeNode *node, T data)
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
                return node->right;
            }
            else if (!node->right)
            {
                return node->left;
            }
            else
            {
                TreeNode *temp = minValueNode(node->right);
                node->data = temp->data;
                node->right = remove(node->right, temp->data);
            }
        }
        return node;
    }

    TreeNode *minValueNode(TreeNode *node)
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

    bool search(TreeNode *node, T data)
    {
        if (!node)
        {
            return false;
        }
        if (data == node->data)
        {
            return true;
        }
        if (data < node->data)
        {
            return search(node->left, data);
        }
        return search(node->right, data);
    }

    void inorder(TreeNode *node)
    {
        if (!node)
        {
            return;
        }
        inorder(node->left);
        std::cout << node->data << " ";
        inorder(node->right);
    }

    void inorder()
    {
        inorder(root);
    }
};

void test_binary_tree()
{
    BinaryTree<int> tree;
    tree.insert(5);
    tree.insert(2);
    tree.insert(7);
    tree.insert(4);
    tree.insert(9);

    std::cout << "In-order traversal: ";
    tree.inorder();
    std::cout << std::endl;

    std::cout << "Search for 4: " << tree.search(4) << std::endl;
    std::cout << "Search for 10: " << tree.search(10) << std::endl;

    std::cout << "Remove node 7: ";
    tree.remove(7);
    tree.inorder();
    std::cout << std::endl;
}

int main()
{
    test_binary_tree();
    return 0;
}