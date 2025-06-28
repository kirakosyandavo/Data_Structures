#include <iostream>
using namespace std;

template<typename T>
class AVL_Tree {
    struct TreeNode {
        TreeNode* left;
        TreeNode* right;
        T value;
        int height;

        TreeNode(T values)
            : left(nullptr), right(nullptr), value(values), height(0) {}
    };

    TreeNode* root;

    TreeNode* find_successor(TreeNode* node) {
        if (node->left == nullptr) return node;
        return find_successor(node->left);
    }

    TreeNode* find_predecessor(TreeNode* node) {
        if (node->right == nullptr) return node;
        return find_predecessor(node->right);
    }

    TreeNode* right_rotate(TreeNode* ptr) {
        TreeNode* y = ptr->left;
        ptr->left = y->right;
        y->right = ptr;
        ptr->height = 1 + max(height(ptr->left), height(ptr->right));
        y->height = 1 + max(height(y->left), height(y->right));
        return y;
    }

    TreeNode* left_rotate(TreeNode* ptr) {
        TreeNode* y = ptr->right;
        ptr->right = y->left;
        y->left = ptr;
        ptr->height = 1 + max(height(ptr->left), height(ptr->right));
        y->height = 1 + max(height(y->left), height(y->right));
        return y;
    }

    int Balance_factory(TreeNode* node) {
        return height(node->left) - height(node->right);
    }

public:
    int height(TreeNode* node) {
        if (node == nullptr) return -1;
        return node->height;
    }

    void inorder_traversal(TreeNode* node) {
        if (node == nullptr) return;
        inorder_traversal(node->left);
        cout << node->value << " ";
        inorder_traversal(node->right);
    }

    void preorder_traversal(TreeNode* node) {
        if (node == nullptr) return;
        cout << node->value << " ";
        preorder_traversal(node->left);
        preorder_traversal(node->right);
    }

    void postorder_traversal(TreeNode* node) {
        if (node == nullptr) return;
        postorder_traversal(node->left);
        postorder_traversal(node->right);
        cout << node->value << " ";
    }

    TreeNode* helper_insert(TreeNode* node, T values) {
        if (node == nullptr) {
            node = new TreeNode(values);
            return node;
        }

        if (node->value > values) {
            node->left = helper_insert(node->left, values);
        } else {
            node->right = helper_insert(node->right, values);
        }

        node->height = 1 + max(height(node->right), height(node->left));

        if (Balance_factory(node) > 1 && values < node->left->value) {
            node = right_rotate(node);
            return node;
        }

        if (Balance_factory(node) > 1 && values > node->left->value) {
            node->left = left_rotate(node->left);
            return right_rotate(node);
        }

        if (Balance_factory(node) < -1 && values > node->right->value) {
            return left_rotate(node);
        }

        if (Balance_factory(node) < -1 && values < node->right->value) {
            node->right = right_rotate(node->right);
            return left_rotate(node);
        }

        return node;
    }

    TreeNode* helper_deletion(TreeNode* node, T values) {
        if (node == nullptr) return node;

        if (node->value < values) {
            node->right = helper_deletion(node->right, values);
        } else if (node->value > values) {
            node->left = helper_deletion(node->left, values);
        } else {
            if (node->left == nullptr) {
                TreeNode* temp = node->right;
                delete node;
                return temp;
            }

            if (node->right == nullptr) {
                TreeNode* temp = node->left;
                delete node;
                return temp;
            }

            TreeNode* ptr = find_successor(node->right);
            node->value = ptr->value;
            node->right = helper_deletion(node->right, ptr->value);
        }

        if (node->left == nullptr && node->right == nullptr) {
            node->height = 0;
        } else {
            node->height = 1 + max(height(node->left), height(node->right));
        }

        if (Balance_factory(node) > 1 && Balance_factory(node->left) >= 0) {
            return right_rotate(node);
        }

        if (Balance_factory(node) > 1 && Balance_factory(node->left) < 0) {
            node->left = left_rotate(node->left);
            return right_rotate(node);
        }

        if (Balance_factory(node) < -1 && Balance_factory(node->right) <= 0) {
            return left_rotate(node);
        }

        if (Balance_factory(node) < -1 && Balance_factory(node->right) > 0) {
            node->right = right_rotate(node->right);
            return left_rotate(node);
        }

        return node;
    }

public:
    AVL_Tree() : root(nullptr) {}

    void insert(T values) {
        root = helper_insert(root, values);
    }

    void deleted(T values) {
        root = helper_deletion(root, values);
    }

    void print_inorder() {
        inorder_traversal(root);
    }

    void print_preorder() {
        preorder_traversal(root);
    }

    void print_postorder() {
        postorder_traversal(root);
    }
};
